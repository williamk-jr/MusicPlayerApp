#include "service.h"

namespace iamaprogrammer {
  void Service::start(long interval) {
    this->thread = std::thread([this, interval]() {
      while (!this->stopped) {
        this->action();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
      }
    });
  }

  void Service::stop() {
    this->stopped.store(true);
    if (this->thread.joinable()) {
      this->thread.join();
    }
  }
}