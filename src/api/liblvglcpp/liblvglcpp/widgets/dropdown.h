#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class DropdownWidget: public LvObject {
    public:
      DropdownWidget(LvObject* parent);

      void setSelected(uint16_t idx);
      uint16_t getSelected();
      void setOptions(const char * options);
  };
}
