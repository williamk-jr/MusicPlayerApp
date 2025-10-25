#include "audio_buffer.h"

namespace iamaprogrammer {
  AudioBuffer::AudioBuffer(AudioFileDescriptor* audioFileDescriptor, int framesPerBuffer, int readSize):
    audioFileDescriptor(audioFileDescriptor),
    framesPerBuffer(framesPerBuffer),
    readSize(readSize)
  {
    std::cout << "BUFFER" << std::endl;
    std::cout << "\tCreated Shared Buffer: " << std::endl;
    std::cout << "\t\tFrames Per Buffer: " << this->framesPerBuffer << std::endl;
    std::cout << "\t\tRead Size: " << this->readSize << std::endl;
  }

  void AudioBuffer::push(AudioChunk& chunk) {
    if (chunk.getSize() != this->framesPerBuffer) {
      throw std::runtime_error("Mismatch between chunk size and frames per buffer.");
    }
    this->buffer.push(chunk);
  }

  AudioChunk& AudioBuffer::front() {
    return this->buffer.front();
  }

  void AudioBuffer::pop() {
    this->buffer.pop();
  }

  size_t AudioBuffer::size() {
    return this->buffer.size();
  }

  const AudioFileDescriptor& AudioBuffer::getAudioFileDescriptor() {
    return *this->audioFileDescriptor;
  }

  const int AudioBuffer::getFramesPerBuffer() {
    return this->framesPerBuffer;
  }

  const int AudioBuffer::getReadSize() {
    return this->readSize;
  }
}