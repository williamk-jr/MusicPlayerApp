#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ArcWidget: public LvObject {
    public:
      ArcWidget(LvObject* parent);

      void setStartAngle(int32_t start);
      void setEndAngle(int32_t end);
      void setAngles(int32_t start, int32_t end);
      void setValue(int32_t value);
      int32_t getValue();
  };
}
