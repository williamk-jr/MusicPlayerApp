#include "app_events.h"

namespace iamaprogrammer {
  uint32_t EVENT_FILE_SYSTEM_UPDATE = lv_event_register_id();
  uint32_t EVENT_PLAYLIST_UPDATE = lv_event_register_id();
  uint32_t EVENT_SONG_UPDATE = lv_event_register_id();
}