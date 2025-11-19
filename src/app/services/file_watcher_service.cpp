#include "file_watcher_service.h"

namespace iamaprogrammer {
  FileWatcherService::FileWatcherService(EventBus* eventBus, std::filesystem::path path) : 
    eventBus(eventBus), path(path) {

  }
  
  void FileWatcherService::action() {
    if (std::filesystem::exists(path)) {
      
    }

    //this->eventBus->publish(EVENT_FILE_SYSTEM_UPDATE, nullptr);
  }
}