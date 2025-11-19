#pragma once

#include <liblvglcpp/lvgl_cpp.h>

#include "../services/file_watcher_service.h"

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

namespace iamaprogrammer {
  class MainPage {
    public:
      MainPage();
      void init(lv_display_t* disp);

    private:
      iamaprogrammer::WidgetPointer<iamaprogrammer::Grid> grid;
      iamaprogrammer::WidgetPointer<iamaprogrammer::GridCell> navBar;
      iamaprogrammer::WidgetPointer<iamaprogrammer::GridCell> playlists;
      iamaprogrammer::WidgetPointer<iamaprogrammer::GridCell> songs;
      iamaprogrammer::WidgetPointer<iamaprogrammer::GridCell> song;

  };
}