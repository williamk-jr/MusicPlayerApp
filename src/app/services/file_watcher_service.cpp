#include "file_watcher_service.h"

namespace iamaprogrammer {
  FileWatcherService::FileWatcherService(std::filesystem::path path) : 
    path(path) {

  }
  
  void FileWatcherService::action() {
    if (std::filesystem::exists(path)) {
      
    }

    //this->eventBus->publish(EVENT_FILE_SYSTEM_UPDATE, nullptr);
  }
}