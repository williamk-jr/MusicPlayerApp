#include "grid.h"

namespace iamaprogrammer {
  Grid::Grid(Widget* parent, std::vector<int32_t> columns, std::vector<int32_t> rows) : 
    Grid(parent->getHandle(), columns, rows) {}

  Grid::Grid(lv_obj_t* parent, std::vector<int32_t> columns, std::vector<int32_t> rows) : columns(columns), rows(rows) {
    this->create(parent);

    //this->columns.push_back(LV_GRID_TEMPLATE_LAST);
    //this->rows.push_back(LV_GRID_TEMPLATE_LAST);

    lv_obj_set_grid_dsc_array(this->getHandle(), this->columns.data(), this->rows.data());
    this->setLayout(LV_LAYOUT_GRID);
  }

  void Grid::setGridAlign(lv_grid_align_t column_align, lv_grid_align_t row_align) {
    lv_obj_set_grid_align(this->getHandle(), column_align, row_align);
  }
}