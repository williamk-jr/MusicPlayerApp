#include "led.h"

namespace iamaprogrammer {
  LedWidget::LedWidget(LvObject* parent) :
    LvObject(lv_led_create(parent->getHandle())) {}

  void LedWidget::setOn(bool on) {
    if (on) lv_led_on(this->getHandle()); else lv_led_off(this->getHandle());
  }

  void LedWidget::setBrightness(uint8_t br) {
    lv_led_set_brightness(this->getHandle(), br);
  }
}
