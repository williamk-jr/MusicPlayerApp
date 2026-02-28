#include "keyboard.h"

namespace iamaprogrammer {
  KeyboardWidget::KeyboardWidget(LvObject* parent) :
    LvObject(lv_keyboard_create(parent->getHandle())) {}

  void KeyboardWidget::setTextArea(LvObject* ta) {
    lv_keyboard_set_textarea(this->getHandle(), ta->getHandle());
  }

  void KeyboardWidget::setMode(lv_keyboard_mode_t mode) {
    lv_keyboard_set_mode(this->getHandle(), mode);
  }
}
