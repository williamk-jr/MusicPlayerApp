#include "switch.h"

namespace iamaprogrammer {
  SwitchWidget::SwitchWidget(LvObject* parent) :
    LvObject(lv_switch_create(parent->getHandle())) {}

  void SwitchWidget::setOn(bool on) {
    if(on) lv_obj_add_state(this->getHandle(), LV_STATE_CHECKED);
    else lv_obj_remove_state(this->getHandle(), LV_STATE_CHECKED);
  }

  bool SwitchWidget::isOn() {
    return lv_obj_has_state(this->getHandle(), LV_STATE_CHECKED);
  }
}
