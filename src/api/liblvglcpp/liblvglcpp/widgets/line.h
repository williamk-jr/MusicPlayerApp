#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class LineWidget: public LvObject {
    public:
      LineWidget(LvObject* parent);

      void setPoints(const lv_point_precise_t* points, uint16_t pointCnt);
  };
}
