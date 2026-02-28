#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class LedWidget: public LvObject {
    public:
      LedWidget(LvObject* parent);

      void setOn(bool on);
      void setBrightness(uint8_t br);
  };
}
