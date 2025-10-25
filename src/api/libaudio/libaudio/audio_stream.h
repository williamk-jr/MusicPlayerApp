#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>

#include "audio_chunk.h"
#include "audio_file_descriptor.h"
#include "stream/ibasic_audio_stream.h"
#include "reader/iaudio_reader.h"
#include "resampler/iaudio_resampler.h"

namespace iamaprogrammer {
  class AudioStream {
    public:
      enum StreamState {
        OPEN,
        CLOSED
      };
      
      enum PlayingState {
        PLAYING,
        SEEKING,
        STOPPED,
        BUFFERING
      };

      AudioStream();
      AudioStream(IAudioReader* reader, IAudioResampler* resampler, IBasicAudioStream* stream);

      void setFile(std::filesystem::path filePath);

      void setup();

      void start();
      void seek(float seconds);
      void stop();

      void end();

      std::filesystem::path getFilePath();
      PlayingState getPlayingState();
      StreamState getStreamState();

    private:
      static int MAX_LOADED_CHUNKS;
      
      // Essential
      std::filesystem::path filePath;
      IAudioReader* reader;
      IAudioResampler* resampler;
      IBasicAudioStream* basicAudioStream;
      std::thread audioReaderThread;

      // State
      PlayingState playingState = PlayingState::STOPPED;
      StreamState streamState = StreamState::CLOSED;

      void handleError();
      void audioReaderThreadCallback();
  };
}