#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class AnimImageWidget: public LvObject {
    public:
      AnimImageWidget(LvObject* parent);

      void setSrc(const void ** dsc, size_t num);
      void start();
      void setDuration(uint32_t d);
      uint32_t getDuration();
  };
}
