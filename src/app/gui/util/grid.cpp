#include "grid.h"

namespace iamaprogrammer {
  lv_obj_t* lvext_grid_create(lv_obj_t* parent, const std::vector<int32_t>& columns, const std::vector<int32_t>& rows) {
    lv_obj_t* grid = lv_obj_create(parent);
    lvext_obj_set_style_default(grid);
    lv_obj_set_grid_dsc_array(grid, columns.data(), rows.data());
    lv_obj_set_layout(grid, LV_LAYOUT_GRID);
    return grid;
  }

  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, lv_grid_align_t column_align, int32_t col_pos, int32_t col_span, lv_grid_align_t row_align, int32_t row_pos, int32_t row_span) {
    lv_obj_t* gridCell = lv_obj_create(parent);
    lvext_obj_set_style_default(gridCell);
    lv_obj_set_grid_cell(gridCell, column_align, col_pos, col_span, row_align, row_pos, row_span);
    return gridCell;
  }

  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, lv_grid_align_t column_align, int32_t col_pos, lv_grid_align_t row_align, int32_t row_pos) {
    return lvext_grid_cell_create(parent, column_align, col_pos, 1, row_align, row_pos, 1);
  }
  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, int32_t col_pos, int32_t col_span, int32_t row_pos, int32_t row_span) {
    return lvext_grid_cell_create(parent, LV_GRID_ALIGN_START, col_pos, col_span, LV_GRID_ALIGN_START, row_pos, row_span);
  }
  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, int32_t col_pos, int32_t row_pos) {
    return lvext_grid_cell_create(parent, LV_GRID_ALIGN_START, col_pos, 1, LV_GRID_ALIGN_START, row_pos, 1);
  }
}