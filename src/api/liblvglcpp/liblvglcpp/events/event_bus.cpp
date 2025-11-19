#include "event_bus.h"

namespace iamaprogrammer {
  void EventBus::subscribe(Widget* subscriber, uint32_t eventId) {
    this->mtx.lock();
    this->subscribers[eventId].push_back(subscriber);
    this->mtx.unlock();
  }

  void EventBus::publish(uint32_t eventId, void* data) {
    std::future<void> task = std::async(&EventBus::queryEvents, this, eventId, data);
  }

  void EventBus::queryEvents(uint32_t eventId, void* data) {
    this->mtx.lock();
    for (Widget* subscriber : this->subscribers[eventId]) {
      subscriber->sendEvent(eventId, data);
    }
    this->mtx.unlock();
  }
}