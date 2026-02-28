#pragma once

#include <string>

extern "C" {
  #include "lvgl/lvgl.h"
}

namespace iamaprogrammer {
  extern uint32_t EVENT_FILE_SYSTEM_UPDATE;
  extern uint32_t EVENT_PLAYLIST_UPDATE;
  extern uint32_t EVENT_SONG_UPDATE;

  struct EventPlaylistUpdateData {
    std::string playlistName;
  };
}