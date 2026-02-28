#pragma once
#include <filesystem>
#include <vector>

#include <libaudio/audio_stream.h>
#include "registry/src/registry/registry.h"

namespace iamaprogrammer {

  class PlaylistManager {
    public:
      PlaylistManager(iamaprogrammer::Registry& registry);

      std::vector<std::string> getPlaylists();

    private:
      iamaprogrammer::Registry& registry; //= Registry(PATH_DATA / "library.db");
      
  };
}