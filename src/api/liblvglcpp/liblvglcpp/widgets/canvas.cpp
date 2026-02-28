#include "canvas.h"

namespace iamaprogrammer {
  CanvasWidget::CanvasWidget(LvObject* parent) :
    LvObject(lv_canvas_create(parent->getHandle())) {}

  void CanvasWidget::setBuffer(void* buf, int32_t w, int32_t h, lv_color_format_t cf) {
    lv_canvas_set_buffer(this->getHandle(), buf, w, h, cf);
  }

  void CanvasWidget::setPixel(int32_t x, int32_t y, lv_color_t color, lv_opa_t p) {
    lv_canvas_set_px(this->getHandle(), x, y, color, p);
  }

  void CanvasWidget::fillBg(lv_color_t color) {
    lv_canvas_fill_bg(this->getHandle(), color, LV_OPA_COVER);
  }
}
