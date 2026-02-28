#include "spinbox.h"

namespace iamaprogrammer {
  SpinboxWidget::SpinboxWidget(LvObject* parent) :
    LvObject(lv_spinbox_create(parent->getHandle())) {}

  void SpinboxWidget::setValue(int32_t v) {
    lv_spinbox_set_value(this->getHandle(), v);
  }

  int32_t SpinboxWidget::getValue() {
    return lv_spinbox_get_value(this->getHandle());
  }

  void SpinboxWidget::setStep(int32_t step) {
    lv_spinbox_set_step(this->getHandle(), step);
  }
}
