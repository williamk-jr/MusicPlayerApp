#include "grid_cell.h"

namespace iamaprogrammer {
  GridCell::GridCell(iamaprogrammer::Grid& grid, int32_t col_pos, int32_t row_pos) :
    GridCell(grid, LV_GRID_ALIGN_START, col_pos, LV_GRID_ALIGN_START, row_pos) {}

  GridCell::GridCell(iamaprogrammer::Grid& grid, int32_t col_pos, int32_t col_span, int32_t row_pos, int32_t row_span) :
    GridCell(grid, LV_GRID_ALIGN_START, col_pos, col_span, LV_GRID_ALIGN_START, row_pos, row_span) {}

  GridCell::GridCell(iamaprogrammer::Grid& grid, lv_grid_align_t column_align, int32_t col_pos, lv_grid_align_t row_align, int32_t row_pos) : 
    GridCell(grid, column_align, col_pos, 1, row_align, row_pos, 1) {}

  GridCell::GridCell(iamaprogrammer::Grid& grid, lv_grid_align_t column_align, int32_t col_pos, int32_t col_span, lv_grid_align_t row_align, int32_t row_pos, int32_t row_span) 
  : LvObject(lv_obj_create(grid.getHandle())) {
    lv_obj_set_grid_cell(this->getHandle(), column_align, col_pos, col_span, row_align, row_pos, row_span);
  }
}