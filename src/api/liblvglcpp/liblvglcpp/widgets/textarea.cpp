#include "textarea.h"

namespace iamaprogrammer {
  TextAreaWidget::TextAreaWidget(LvObject* parent) :
    LvObject(lv_textarea_create(parent->getHandle())) {}

  void TextAreaWidget::setText(const std::string& txt) {
    lv_textarea_set_text(this->getHandle(), txt.c_str());
  }

  const char* TextAreaWidget::getText() {
    return lv_textarea_get_text(this->getHandle());
  }
}
