#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class KeyboardWidget: public LvObject {
    public:
      KeyboardWidget(LvObject* parent);

      void setTextArea(LvObject* ta);
      void setMode(lv_keyboard_mode_t mode);
  };
}
