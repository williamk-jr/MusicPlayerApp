#include "button.h"

namespace iamaprogrammer {
  ButtonWidget::ButtonWidget(Widget* parent) {
    this->create(parent);
  }

  ButtonWidget::ButtonWidget(lv_obj_t* parent) {
    this->create(parent);
  }

  void ButtonWidget::create(Widget* parent) {
    this->create(parent->getHandle());
  }

  void ButtonWidget::create(lv_obj_t* parent) {
    this->assign(
      lv_btn_create(parent)
    );
  }
}