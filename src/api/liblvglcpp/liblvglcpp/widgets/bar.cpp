#include "bar.h"

namespace iamaprogrammer {
  BarWidget::BarWidget(LvObject* parent) :
    LvObject(lv_bar_create(parent->getHandle())) {}

  void BarWidget::setValue(int32_t value, bool animate) {
    lv_bar_set_value(this->getHandle(), value, animate ? LV_ANIM_ON : LV_ANIM_OFF);
  }

  int32_t BarWidget::getValue() {
    return lv_bar_get_value(this->getHandle());
  }

  void BarWidget::setRange(int32_t min, int32_t max) {
    lv_bar_set_range(this->getHandle(), min, max);
  }
}
