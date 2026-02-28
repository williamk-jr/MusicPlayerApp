#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class Texture3DWidget: public LvObject {
    public:
      Texture3DWidget(LvObject* parent);

      void setSrc(const char* src);
  };
}
