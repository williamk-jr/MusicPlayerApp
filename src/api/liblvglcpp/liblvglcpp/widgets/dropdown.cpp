#include "dropdown.h"

namespace iamaprogrammer {
  DropdownWidget::DropdownWidget(LvObject* parent) :
    LvObject(lv_dropdown_create(parent->getHandle())) {}

  void DropdownWidget::setSelected(uint16_t idx) {
    lv_dropdown_set_selected(this->getHandle(), idx);
  }

  uint16_t DropdownWidget::getSelected() {
    return lv_dropdown_get_selected(this->getHandle());
  }

  void DropdownWidget::setOptions(const char * options) {
    lv_dropdown_set_options(this->getHandle(), options);
  }
}
