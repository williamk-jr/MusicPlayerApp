#include "button.h"

namespace iamaprogrammer {
  ButtonWidget::ButtonWidget(Widget* parent) {
    this->create(parent->getHandle());
  }

  ButtonWidget::ButtonWidget(lv_obj_t* parent) {
    this->create(parent);
  }

  void ButtonWidget::create(lv_obj_t* parent) {
    this->assign(
      lv_btn_create(parent)
    );
  }
}