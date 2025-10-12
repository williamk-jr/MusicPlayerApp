#pragma once

#include "widget.h"

namespace iamaprogrammer {
  class ButtonWidget: public Widget {
    public:
      ButtonWidget(Widget* parent);
      ButtonWidget(lv_obj_t* parent);

    protected:
      void create(lv_obj_t* parent) override;
  };
}