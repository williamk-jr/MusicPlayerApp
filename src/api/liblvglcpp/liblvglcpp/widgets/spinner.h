#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class SpinnerWidget: public LvObject {
    public:
      SpinnerWidget(LvObject* parent);

      void setAnimParams(uint32_t duration, uint32_t angle);
  };
}
