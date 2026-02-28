#include "table.h"

namespace iamaprogrammer {
  TableWidget::TableWidget(LvObject* parent) :
    LvObject(lv_table_create(parent->getHandle())) {}

  void TableWidget::setCellValue(uint16_t row, uint16_t col, const std::string& txt) {
    lv_table_set_cell_value(this->getHandle(), row, col, txt.c_str());
  }

  const char* TableWidget::getCellValue(uint16_t row, uint16_t col) {
    return lv_table_get_cell_value(this->getHandle(), row, col);
  }

  void TableWidget::setRowCnt(uint16_t rows) {
    lv_table_set_row_cnt(this->getHandle(), rows);
  }

  void TableWidget::setColCnt(uint16_t cols) {
    lv_table_set_col_cnt(this->getHandle(), cols);
  }
}
