#include "roller.h"

namespace iamaprogrammer {
  RollerWidget::RollerWidget(LvObject* parent) :
    LvObject(lv_roller_create(parent->getHandle())) {}

  void RollerWidget::setOptions(const char * opts) {
    lv_roller_set_options(this->getHandle(), opts, LV_ROLLER_MODE_NORMAL);
  }

  void RollerWidget::setSelected(uint16_t idx) {
    lv_roller_set_selected(this->getHandle(), idx, LV_ANIM_OFF);
  }

  uint16_t RollerWidget::getSelected() {
    return lv_roller_get_selected(this->getHandle());
  }
}
