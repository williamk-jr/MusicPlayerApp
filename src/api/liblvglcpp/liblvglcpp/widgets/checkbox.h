#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class CheckboxWidget: public LvObject {
    public:
      CheckboxWidget(LvObject* parent);

      void setChecked(bool checked);
      bool isChecked();
  };
}
