#pragma once

#include <thread>
#include <atomic>
#include <chrono>

namespace iamaprogrammer {
  class Service {
    public:

      void start(long interval);
      void stop();

      virtual void action() = 0;
    private:
      std::atomic<bool> stopped = false;
      std::thread thread;
  };
}