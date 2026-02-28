#pragma once

#include "lv_object.h"
#include <string>

namespace iamaprogrammer {
  class MsgBoxWidget: public LvObject {
    public:
      MsgBoxWidget(LvObject* parent);

      void addCloseButton();
      void addFooterButton(const std::string& text);
      void addHeaderButton(const std::string& text);

      void addText(const std::string& text);
  };
}
