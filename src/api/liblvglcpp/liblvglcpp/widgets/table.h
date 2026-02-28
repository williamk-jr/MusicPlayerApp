#pragma once

#include "lv_object.h"
#include <string>

namespace iamaprogrammer {
  class TableWidget: public LvObject {
    public:
      TableWidget(LvObject* parent);

      void setCellValue(uint16_t row, uint16_t col, const std::string& txt);
      const char* getCellValue(uint16_t row, uint16_t col);
      void setRowCnt(uint16_t rows);
      void setColCnt(uint16_t cols);
  };
}
