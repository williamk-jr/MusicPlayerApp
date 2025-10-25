#pragma once
#include <sndfile.h>
#include <queue>
#include <filesystem>
#include <iostream>

#include "audio_chunk.h"
#include "audio_file_descriptor.h"


namespace iamaprogrammer {
  class AudioBuffer {
  public:
    AudioBuffer(AudioFileDescriptor* audioFileDescriptor, int framesPerBuffer, int readSize);

    void push(AudioChunk& chunk);
    AudioChunk& front();
    void pop();

    size_t size();

    const AudioFileDescriptor& getAudioFileDescriptor();
    const int getFramesPerBuffer();
    const int getReadSize();

  private:
    std::queue<AudioChunk> buffer;
    
    AudioFileDescriptor* audioFileDescriptor;
    int framesPerBuffer;
    int readSize;
  };
}