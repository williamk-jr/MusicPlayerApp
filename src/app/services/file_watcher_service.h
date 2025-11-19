#pragma once

#include <filesystem>
#include <liblvglcpp/lvgl_cpp.h>

#include "service.h"
#include "../app_events.h"

namespace iamaprogrammer {
  class FileWatcherService : public Service {
    public:
      FileWatcherService(EventBus* eventBus, std::filesystem::path path);

      void action() override;

    private:
      EventBus* eventBus = nullptr;
      std::filesystem::path path;
  };
}