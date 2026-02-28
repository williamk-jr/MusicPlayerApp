#include "checkbox.h"
#include "checkbox.h"

namespace iamaprogrammer {
  CheckboxWidget::CheckboxWidget(LvObject* parent) :
    LvObject(lv_checkbox_create(parent->getHandle())) {}

  void CheckboxWidget::setChecked(bool checked) {
    lv_obj_set_state(this->getHandle(), LV_STATE_CHECKED, checked);
  }

  bool CheckboxWidget::isChecked() {
    return lv_obj_has_state(this->widget, LV_STATE_CHECKED);
  }
}
