#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ListWidget: public LvObject {
    public:
      ListWidget() = default;
      ListWidget(LvObject& parent);

      lv_obj_t* addButton(const void * icon, const char * txt);
      lv_obj_t* addText(const char * txt);

      const char* getButtonText(lv_obj_t* btn);
      void setButtonText(lv_obj_t* btn, const char * txt);
  };
}
