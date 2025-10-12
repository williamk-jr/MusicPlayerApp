#pragma once
#include "../audio_file_descriptor.h"
#include "../audio_chunk.h"
#include "../resampler/iaudio_resampler.h"

#include <queue>

namespace iamaprogrammer {
  class IAudioReader {
  public:
    virtual size_t read(IAudioResampler* resampler, AudioBuffer& buffer) = 0;
    virtual void seek(size_t frames, int whence) = 0;

    virtual void* getReadBuffer() = 0;
    virtual AudioFileDescriptor* getAudioFileDescriptor() = 0;
    virtual int getReadSize() = 0;

    virtual void close() = 0;
  };
}