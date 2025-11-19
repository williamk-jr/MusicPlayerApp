#pragma once

#include <vector>
#include <map>
#include <queue>
#include <future>
#include <mutex>

extern "C" {
  #include "lvgl/lvgl.h"
}

#include "../widgets/widget.h"

namespace iamaprogrammer {
  class EventBus {
    public:
      void subscribe(Widget* subscriber, uint32_t eventId);
      void publish(uint32_t eventId, void* data);
      
    private:
      std::mutex mtx;
      std::map<uint32_t, std::vector<Widget*>> subscribers;

      void queryEvents(uint32_t eventId, void* data);
  };
}