#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class RollerWidget: public LvObject {
    public:
      RollerWidget(LvObject* parent);

      void setOptions(const char * opts);
      void setSelected(uint16_t idx);
      uint16_t getSelected();
  };
}
