#pragma once

#include <vector>
#include <map>
#include <queue>
#include <future>
#include <mutex>
#include <functional>

extern "C" {
  #include "lvgl/lvgl.h"
}

#include "messages/operation_list_message.h"
#include <liblvglcpp/lvgl_cpp.h>

namespace iamaprogrammer {
  class EventBus;

  typedef std::function<void(LvObject& subscriber, EventBus& eventBus, std::shared_ptr<void>)> lvext_subscription_cb_t;

  struct Event {
    uint32_t id;
    std::shared_ptr<void> data;
  };

  class EventBus {
    public:
      void subscribe(LvObject& subscriber, uint32_t eventId, lvext_subscription_cb_t cb);

      template<typename T>
      void publish(uint32_t eventId, std::shared_ptr<T> data);

      void queryEvent();
      
    private:
      std::mutex mtx;
      std::queue<Event> eventQueue;
      std::map<uint32_t, std::vector<std::pair<LvObject&, lvext_subscription_cb_t>>> subscribers;
      
      template<typename T>
      void publishAsync(uint32_t eventId, std::shared_ptr<T> data);
  };

  template<typename T>
  void EventBus::publish(uint32_t eventId, std::shared_ptr<T> data) {
    std::future<void> task = std::async(&EventBus::publishAsync<T>, this, eventId, data);
  }

  template<typename T>
  void EventBus::publishAsync(uint32_t eventId, std::shared_ptr<T> data) {
    this->mtx.lock();
    this->eventQueue.push({eventId, data});
    this->mtx.unlock();
  }
}