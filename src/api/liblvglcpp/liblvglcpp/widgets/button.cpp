#include "button.h"

namespace iamaprogrammer {
  ButtonWidget::ButtonWidget(LvObject* parent) : 
    LvObject(lv_button_create(parent->getHandle())) {}
}