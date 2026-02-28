#pragma once

#include <iostream>
#include <vector>

#include "grid.h"
#include "../lv_object.h"
#include "../../lvgl_cpp_util.h"

namespace iamaprogrammer {
  class GridCell: public LvObject {
    public:
      GridCell() = default;

      GridCell(iamaprogrammer::Grid& grid, int32_t col_pos, int32_t row_pos);
      GridCell(iamaprogrammer::Grid& grid, int32_t col_pos, int32_t col_span, int32_t row_pos, int32_t row_span);
      GridCell(iamaprogrammer::Grid& grid, lv_grid_align_t column_align, int32_t col_pos, lv_grid_align_t row_align, int32_t row_pos);
      GridCell(iamaprogrammer::Grid& grid, lv_grid_align_t column_align, int32_t col_pos, int32_t col_span, lv_grid_align_t row_align, int32_t row_pos, int32_t row_span);

    private:

  };
}