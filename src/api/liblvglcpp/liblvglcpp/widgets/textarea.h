#pragma once

#include "lv_object.h"
#include <string>

namespace iamaprogrammer {
  class TextAreaWidget: public LvObject {
    public:
      TextAreaWidget(LvObject* parent);

      void setText(const std::string& txt);
      const char* getText();
  };
}
