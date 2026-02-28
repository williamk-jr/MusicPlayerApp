#include "msgbox.h"

namespace iamaprogrammer {
  MsgBoxWidget::MsgBoxWidget(LvObject* parent) :
    LvObject(lv_msgbox_create(parent->getHandle())) {}

  void MsgBoxWidget::addCloseButton() {
    lv_msgbox_add_close_button(this->widget);
  }

  void MsgBoxWidget::addFooterButton(const std::string& text) {
    lv_msgbox_add_footer_button(this->widget, text.c_str());
  }

  void MsgBoxWidget::addHeaderButton(const std::string& text) {
    lv_msgbox_add_header_button(this->widget, text.c_str());
  }

  void MsgBoxWidget::addText(const std::string& text) {
    lv_msgbox_add_text(this->widget, text.c_str());
  }
}
