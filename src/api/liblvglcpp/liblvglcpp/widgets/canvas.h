#pragma once

#include "lv_object.h"
#include <cstdint>

namespace iamaprogrammer {
  class CanvasWidget: public LvObject {
    public:
      CanvasWidget(LvObject* parent);

      void setBuffer(void* buf, int32_t w, int32_t h, lv_color_format_t cf);
      void setPixel(int32_t x, int32_t y, lv_color_t color, lv_opa_t p);
      void fillBg(lv_color_t color);
  };
}
