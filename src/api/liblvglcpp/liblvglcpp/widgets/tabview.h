#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class TabViewWidget: public LvObject {
    public:
      TabViewWidget(LvObject* parent);

      lv_obj_t* addTab(const char* name);
  };
}
