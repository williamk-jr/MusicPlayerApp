#include "menu.h"

namespace iamaprogrammer {
  MenuWidget::MenuWidget(LvObject* parent) :
    LvObject(lv_menu_create(parent->getHandle())) {}

  void MenuWidget::setModeRootBackButton(lv_menu_mode_root_back_button_t mode) {
    lv_menu_set_mode_root_back_button(this->getHandle(), mode);
  }
}
