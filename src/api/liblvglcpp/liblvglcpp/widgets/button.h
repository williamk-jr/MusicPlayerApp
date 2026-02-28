#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ButtonWidget: public LvObject {
    public:
      ButtonWidget() = default;
      ButtonWidget(LvObject* parent);
  };
}