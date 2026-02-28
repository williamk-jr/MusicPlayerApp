#include "grid.h"

namespace iamaprogrammer {
  Grid::Grid(LvObject& parent, std::vector<int32_t>& columns, std::vector<int32_t>& rows) : LvObject(lv_obj_create(parent.getHandle())) {
    lv_obj_set_grid_dsc_array(this->widget, columns.data(), rows.data());
    this->setLayout(LV_LAYOUT_GRID);
  }

  Grid::Grid(lv_obj_t* parent, std::vector<int32_t>& columns, std::vector<int32_t>& rows) : LvObject(lv_obj_create(parent)) {
    lv_obj_set_grid_dsc_array(this->widget, columns.data(), rows.data());
    this->setLayout(LV_LAYOUT_GRID);
  }

  void Grid::setGridAlign(lv_grid_align_t column_align, lv_grid_align_t row_align) {
    lv_obj_set_grid_align(this->getHandle(), column_align, row_align);
  }
}