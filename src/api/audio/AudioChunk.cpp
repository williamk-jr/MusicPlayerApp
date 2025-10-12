//#include "AudioChunk.h"
#include "AudioChunk.h"

namespace iamaprogrammer {

  AudioChunk::AudioChunk() {}

  AudioChunk::AudioChunk(long size) : size(size) {
    this->buffer = std::vector<float>(size);
  }

  std::vector<float>* AudioChunk::data() {
    return &buffer;
  }
}