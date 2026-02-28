#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ImageButtonWidget: public LvObject {
    public:
      ImageButtonWidget(LvObject* parent);

      void setSrc(const char* src);
  };
}
