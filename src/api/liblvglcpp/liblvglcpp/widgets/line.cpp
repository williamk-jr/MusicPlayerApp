#include "line.h"

namespace iamaprogrammer {
  LineWidget::LineWidget(LvObject* parent) :
    LvObject(lv_line_create(parent->getHandle())) {}

  void LineWidget::setPoints(const lv_point_precise_t* points, uint16_t pointCnt) {
    lv_line_set_points(this->getHandle(), points, pointCnt);
  }
}
