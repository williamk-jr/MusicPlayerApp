#include "port_audio_stream.h"

namespace iamaprogrammer {

  PortAudioStream::PortAudioStream(AudioBuffer* audioBuffer) {
    this->audioBuffer = audioBuffer;
  }

  void PortAudioStream::openStream() {
    std::cout << "AUDIO STREAM" << std::endl;
    std::cout << "\tCreating Stream Data." << std::endl;

    this->audioStreamData = AudioStreamData{
      &this->audioBuffer->getAudioFileDescriptor(),
      this->audioBuffer
    };

    std::cout << "\tGetting Output Device." << std::endl;
    PaDeviceIndex device = Pa_GetDefaultOutputDevice();
    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(device);

    PaStreamParameters outputParameters;
    outputParameters.device = device;
    outputParameters.channelCount = this->audioBuffer->getAudioFileDescriptor().channels;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = deviceInfo->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    std::cout << "\tStream Parameters: " << std::endl;
    std::cout << "\t\tDevice Index: " << outputParameters.device << std::endl;
    std::cout << "\t\tChannel Count: " << outputParameters.channelCount << std::endl;
    std::cout << "\t\tSample Format: " << outputParameters.sampleFormat << std::endl;
    std::cout << "\t\tLatency: " << outputParameters.suggestedLatency << std::endl;

    // reader->getReadSize() * resampler->getSampleRateConversionRatio()
    this->error = Pa_OpenStream(
      &this->stream,
      NULL,
      &outputParameters,
      deviceInfo->defaultSampleRate,
      this->audioBuffer->getFramesPerBuffer(), // paFramesPerBufferUnspecified
      paNoFlag,
      paCallback,
      &this->audioStreamData
    );
    std::cout << "\tCreated Audio Stream." << std::endl;
  }

  void PortAudioStream::closeStream() {
    this->error = Pa_CloseStream(this->stream);
  }

  void PortAudioStream::startStream() {
    this->error = Pa_StartStream(this->stream);
  }

  void PortAudioStream::seekStream(int frames) {
    this->audioStreamData.seekOffset = frames;
    this->audioStreamData.seeking = true;
  }

  void PortAudioStream::stopStream() {
    this->error = Pa_StopStream(this->stream);
  }

  bool PortAudioStream::isStreamStopped() {
    return Pa_IsStreamStopped(this->stream);
  }

  bool PortAudioStream::isStreamActive() {
    return Pa_IsStreamActive(this->stream);
  }

  int PortAudioStream::getChannelCount() {
    return this->audioStreamData.data->channels;
  }

  AudioBuffer* PortAudioStream::getAudioBuffer() {
    return this->audioBuffer;
  }

  std::string PortAudioStream::getError() {
    return std::string(Pa_GetErrorText(this->error));
  }

  bool PortAudioStream::hasError() {
    return this->error != paNoError;
  }

  int PortAudioStream::getDeviceIndex() {
    PaDeviceIndex device = Pa_GetDefaultOutputDevice();
    if (device == paNoDevice) {
      throw std::runtime_error("No default output device found.");
    }
    return device;
  }

  const PaDeviceInfo* PortAudioStream::getDeviceInfo() {
    return Pa_GetDeviceInfo(getDeviceIndex());
  }
}