#include "list.h"

namespace iamaprogrammer {
  ListWidget::ListWidget(LvObject& parent) :
    LvObject(lv_list_create(parent.getHandle())) {}

  lv_obj_t* ListWidget::addButton(const void * icon, const char * txt) {
    return lv_list_add_button(this->getHandle(), icon, txt);
  }

  lv_obj_t* ListWidget::addText(const char * txt) {
    return lv_list_add_text(this->getHandle(), txt);
  }

  const char* ListWidget::getButtonText(lv_obj_t* btn) {
    return lv_list_get_button_text(this->getHandle(), btn);
  }

  void ListWidget::setButtonText(lv_obj_t* btn, const char * txt) {
    lv_list_set_button_text(this->getHandle(), btn, txt);
  }
}
