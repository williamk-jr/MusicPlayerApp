#include "scale.h"

namespace iamaprogrammer {
  ScaleWidget::ScaleWidget(LvObject* parent) :
    LvObject(lv_slider_create(parent->getHandle())) {}

  void ScaleWidget::setValue(int32_t v) {
    lv_slider_set_value(this->getHandle(), v, LV_ANIM_OFF);
  }

  int32_t ScaleWidget::getValue() {
    return lv_slider_get_value(this->getHandle());
  }
}
