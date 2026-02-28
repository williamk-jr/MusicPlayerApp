#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include <unordered_set>

#include <libaudio/libaudio/backends/port_audio_backend.h>
#include <libaudio/libaudio/audio_stream.h>

#include "services/file_watcher_service.h"
#include "gui/pages/main_page.h"
#include "event/event_bus.h"
#include "crypt/md5.h"

#include "registry/src/registry/registry.h"

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

namespace iamaprogrammer {
  class App {
    public:
      App();

      void start();
      void tick();
      void stop();

    private:
      ApplicationModel applicationModel;

      lv_display_t* display;
      lv_indev_t* inputDevice;

      iamaprogrammer::MainPage mainpage;

      void startServices();
      void stopServices();

      void createDisplay();
      void createTouchDevice();

      void createGui();
  };
}