#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class SpinboxWidget: public LvObject {
    public:
      SpinboxWidget(LvObject* parent);

      void setValue(int32_t v);
      int32_t getValue();
      void setStep(int32_t step);
  };
}
