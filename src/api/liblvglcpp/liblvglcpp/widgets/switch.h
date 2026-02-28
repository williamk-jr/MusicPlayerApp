#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class SwitchWidget: public LvObject {
    public:
      SwitchWidget(LvObject* parent);

      void setOn(bool on);
      bool isOn();
  };
}
