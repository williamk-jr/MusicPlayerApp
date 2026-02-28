#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ScaleWidget: public LvObject {
    public:
      ScaleWidget(LvObject* parent);

      void setValue(int32_t v);
      int32_t getValue();
  };
}
