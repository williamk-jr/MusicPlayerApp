#pragma once

#include "lv_object.h"
#include <vector>
#include <string>

namespace iamaprogrammer {
  class ButtonMatrixWidget: public LvObject {
    public:
      ButtonMatrixWidget(LvObject* parent);

      void setMap(const std::vector<const char*>& map);
      void setSelected(int32_t id);
      int32_t getSelected();
      void setButtonCtrl(uint16_t btnId, lv_btnmatrix_ctrl_t ctrl);
      void clearButtonCtrl(uint16_t btnId, lv_btnmatrix_ctrl_t ctrl);
  };
}
