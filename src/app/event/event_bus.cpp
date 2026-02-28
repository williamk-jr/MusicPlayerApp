#include "event_bus.h"

namespace iamaprogrammer {
  void EventBus::subscribe(LvObject& subscriber, uint32_t eventId, lvext_subscription_cb_t cb) {
    this->subscribers[eventId].push_back({subscriber, cb});
  }

  void EventBus::queryEvent() {
    if (!this->mtx.try_lock() || this->eventQueue.empty()) {
      return;
    }

    Event event = this->eventQueue.front();
    this->eventQueue.pop();
    
    for (std::pair<LvObject&, lvext_subscription_cb_t> subscriber : this->subscribers[event.id]) {
      subscriber.second(subscriber.first, *this, event.data);
      //lv_obj_send_event(subscriber, (lv_event_code_t)event.id, event.data);
    }
    this->mtx.unlock();
  }
}