#include "SndlibAudioReader.h"

namespace iamaprogrammer {
  SndlibAudioReader::SndlibAudioReader() {

  }

  SndlibAudioReader::SndlibAudioReader(std::filesystem::path filePath, int readSize): 
    readSize(readSize)
  {
    SF_INFO info;

    std::string pathStr = filePath.string();
    const char* pathCStr = pathStr.c_str();

    this->file = sf_open(pathCStr, SFM_READ, &info);
    if (this->file == nullptr) {
      std::cout << "Error opening file: " << pathCStr << std::endl;
    }

    this->audioFileDescriptor.frames = info.frames;
    this->audioFileDescriptor.channels = info.channels;
    this->audioFileDescriptor.sampleRate = info.samplerate;

    // Set up read buffer and initialize sample rate converter.
    this->readBuffer = std::vector<float>(readSize * info.channels);
  }

  size_t SndlibAudioReader::read(IAudioResampler* resampler, AudioBuffer& buffer) {
    int srConvertionRatio = resampler->getSampleRateConversionRatio();
    AudioChunk chunk((this->readSize * srConvertionRatio) * this->audioFileDescriptor.channels);

    long long readCount = sf_readf_float(this->file, this->readBuffer.data(), this->readSize);

    if (srConvertionRatio == 1.0) { // The ratio is the same, no need to convert.
      *(chunk.data()) = this->readBuffer;
    } else {
      resampler->resample(chunk.data()->data());
    }

    if (readCount > 0) {
      buffer.push(chunk);
    }
    return readCount;
  }

  void SndlibAudioReader::seek(size_t frames, int whence) {
    sf_seek(this->file, frames, whence);
  }

  void* SndlibAudioReader::getReadBuffer() {
    return this->readBuffer.data();
  }

  AudioFileDescriptor* SndlibAudioReader::getAudioFileDescriptor() {
    return &this->audioFileDescriptor;
  }

  int SndlibAudioReader::getReadSize() {
    return this->readSize;
  }

  void SndlibAudioReader::close() {
    sf_close(file);
  }
}