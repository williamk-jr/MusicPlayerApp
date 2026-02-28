#pragma once

#include <filesystem>

#include "service.h"
#include "../app_events.h"

namespace iamaprogrammer {
  class FileWatcherService : public Service {
    public:
      FileWatcherService(std::filesystem::path path);

      void action() override;

    private:
      //EventBus* eventBus = nullptr;
      std::filesystem::path path;
  };
}