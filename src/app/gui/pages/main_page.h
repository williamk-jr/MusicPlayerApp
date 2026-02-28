#pragma once
#include <iostream>

#include "page.h"
#include <vector>

#include "../../app_events.h"
#include "../../event/event_bus.h"
#include "../../event/messages/operation_list_message.h"
#include "../../event/observable/observable.h"
#include "registry/src/registry/registry.h"
#include "../widgets/audio_control.h"

#include <liblvglcpp/lvgl_cpp.h>

namespace iamaprogrammer {
  struct MainPageState {
    Observable<std::string> selectedPlaylist;
    Observable<std::string> selectedSongList;
    Observable<std::string> selectedSong;
  };

  class MainPage : public Page {
    public:
      MainPage(ApplicationModel& applicationModel);
      void init(lv_display_t* disp) override;

    private:
      MainPageState state;

      GridCell navBar;
      GridCell playlists;
      GridCell songs;
      GridCell song;

      ListWidget playlistsList;
      ListWidget songsList;
      AudioControlWidget audioControl;

      void eventPlaylistUpdate(LvObject& target, EventBus& eventBus, std::shared_ptr<void> data);
  };
}