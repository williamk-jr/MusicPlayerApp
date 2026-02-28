#include "win.h"

namespace iamaprogrammer {
  WinWidget::WinWidget(LvObject* parent) :
    LvObject(lv_win_create(parent->getHandle())) {}

  lv_obj_t* WinWidget::addTitle(const char* txt) {
    return lv_win_add_title(this->getHandle(), txt);
  }

  lv_obj_t* WinWidget::addButton(const void* icon, int32_t btn_w) {
    return lv_win_add_button(this->getHandle(), icon, btn_w);
  }

  lv_obj_t* WinWidget::getHeader() {
    return lv_win_get_header(this->getHandle());
  }

  lv_obj_t* WinWidget::getContent() {
    return lv_win_get_content(this->getHandle());
  }
}
