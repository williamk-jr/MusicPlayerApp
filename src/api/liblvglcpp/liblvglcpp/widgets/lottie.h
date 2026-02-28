#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class LottieWidget: public LvObject {
    public:
      LottieWidget(LvObject* parent);

      void setSrcFile(const char* file);
      void setBuffer(int32_t w, int32_t h, void* buf);
  };
}
