#pragma once
#include <filesystem>
#include <vector>

#include <libaudio/audio_stream.h>
#include <libaudio/audio_stream_factory.h>
#include <libaudio/backends/port_audio_backend.h>

#include "registry/src/registry/registry.h"

namespace iamaprogrammer {

  class AudioManager {
    public:
      AudioManager(std::filesystem::path& audioLibraryPath, iamaprogrammer::Registry& registry);

      std::vector<std::string> getAudio();
      void selectFromPlaylist(std::string playlist, std::string hash);

      //void playStream(std::string name, int position);
      //void playStream(std::string name);

    private:
      std::filesystem::path& audioLibraryPath;
      iamaprogrammer::Registry& registry; //= Registry(PATH_DATA / "library.db");

      iamaprogrammer::PortAudioBackend audioBackend;
      iamaprogrammer::AudioStream stream;
  };
}