#include "tabview.h"

namespace iamaprogrammer {
  TabViewWidget::TabViewWidget(LvObject* parent) :
    LvObject(lv_tabview_create(parent->getHandle())) {}

  lv_obj_t* TabViewWidget::addTab(const char* name) {
    return lv_tabview_add_tab(this->getHandle(), name);
  }
}
