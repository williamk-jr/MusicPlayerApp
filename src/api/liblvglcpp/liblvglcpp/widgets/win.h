#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class WinWidget: public LvObject {
    public:
      WinWidget(LvObject* parent);

      lv_obj_t* addTitle(const char* txt);
      lv_obj_t* addButton(const void* icon, int32_t btn_w);
      lv_obj_t* getHeader();
      lv_obj_t* getContent();
  };
}
