#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class BarWidget: public LvObject {
    public:
      BarWidget(LvObject* parent);

      void setValue(int32_t value, bool animate=false);
      int32_t getValue();
      void setRange(int32_t min, int32_t max);
  };
}
