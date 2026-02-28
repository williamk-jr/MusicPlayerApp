#include "spinner.h"

namespace iamaprogrammer {
  SpinnerWidget::SpinnerWidget(LvObject* parent) :
    LvObject(lv_spinner_create(parent->getHandle())) {}

  void SpinnerWidget::setAnimParams(uint32_t duration, uint32_t angle) {
    lv_spinner_set_anim_params(this->getHandle(), duration, angle);
  }
}
