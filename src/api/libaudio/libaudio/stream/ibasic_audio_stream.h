#pragma once

#include <string>
#include "../reader/iaudio_reader.h"
#include "../resampler/iaudio_resampler.h"
#include "../audio_buffer.h"

namespace iamaprogrammer {

  /*
  Holds data important to audio streams.

  - data:       File information related to timing.
  - buffer:     File read buffer typically provided by file reader.
  - seeking:    Whether a "seeking" action should happen. (eg. fast-forward/backward)
  - seekOffest: How much to offset audio stream pointer when seeking.
  - start:      The place in which to start reading audio
  */

  class IBasicAudioStream {
  public:
    virtual void openStream() = 0;
    virtual void closeStream() = 0;

    virtual void startStream() = 0;
    virtual void seekStream(int frames) = 0;
    virtual void stopStream() = 0;

    virtual bool isStreamFinished() = 0;
    virtual bool isStreamStopped() = 0;
    virtual bool isStreamActive() = 0;

    virtual long streamPosition() = 0;
    virtual long streamDuration() = 0;

    //virtual double getSampleRate() = 0;
    virtual int getChannelCount() = 0;
    virtual AudioBuffer* getAudioBuffer() = 0;

    virtual std::string getError() = 0;
    virtual bool hasError() = 0;
  protected:
    AudioBuffer* audioBuffer;
  };

  struct AudioStreamData {
    IBasicAudioStream* stream;
    const AudioFileDescriptor* data;
    AudioBuffer* buffer;

    bool seeking = false;
    long seekOffset = 0;
    long start = 0;

    bool streamFinished = true;
  };
}