#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class MenuWidget: public LvObject {
    public:
      MenuWidget(LvObject* parent);

      void setModeRootBackButton(lv_menu_mode_root_back_button_t mode);
  };
}
