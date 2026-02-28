#include "arc.h"

namespace iamaprogrammer {
  ArcWidget::ArcWidget(LvObject* parent) :
    LvObject(lv_arc_create(parent->getHandle())) {}

  void ArcWidget::setStartAngle(int32_t start) {
    lv_arc_set_start_angle(this->getHandle(), start);
  }

  void ArcWidget::setEndAngle(int32_t end) {
    lv_arc_set_end_angle(this->getHandle(), end);
  }

  void ArcWidget::setAngles(int32_t start, int32_t end) {
    lv_arc_set_angles(this->getHandle(), start, end);
  }

  void ArcWidget::setValue(int32_t value) {
    lv_arc_set_value(this->getHandle(), value);
  }

  int32_t ArcWidget::getValue() {
    return lv_arc_get_value(this->getHandle());
  }
}
