#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>

#include <liblvglcpp/lvgl_cpp.h>

#include <libaudio/backends/port_audio_backend.h>
#include <libaudio/reader/sndlib_audio_reader.h>
#include <libaudio/resampler/sr_audio_resampler.h>
#include <libaudio/audio_stream.h>

#include "services/file_watcher_service.h"
#include "gui/main_page.h"

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

namespace iamaprogrammer {
  class App {
    public:
      void start();
      void stop();

    private:
      std::filesystem::path PATH_APP_DATA = "/etc/musicapp";
      std::filesystem::path PATH_AUDIO_LIBRARY = PATH_APP_DATA / "library";
      std::filesystem::path PATH_PLAYLISTS = PATH_APP_DATA / "playlists";

      iamaprogrammer::EventBus eventBus;
      lv_display_t* display = nullptr;
      lv_indev_t* inputDevice = nullptr;

      iamaprogrammer::FileWatcherService fileWatcherService = iamaprogrammer::FileWatcherService(&this->eventBus, this->PATH_APP_DATA);

      iamaprogrammer::MainPage mainpage;

      void startServices();
      void stopServices();

      void createDisplay();
      void createTouchDevice();

      void createGui();
  };
}