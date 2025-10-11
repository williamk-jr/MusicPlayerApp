#pragma once

#include <vector>
#include "../widget.h"
#include "grid.h"

namespace iamaprogrammer {
  class GridCell: public Widget {
    public:
      GridCell(Grid* grid, int32_t col_pos, int32_t row_pos);
      GridCell(Grid* grid, int32_t col_pos, int32_t col_span, int32_t row_pos, int32_t row_span);
      GridCell(Grid* grid, lv_grid_align_t column_align, int32_t col_pos, lv_grid_align_t row_align, int32_t row_pos);
      GridCell(Grid* grid, lv_grid_align_t column_align, int32_t col_pos, int32_t col_span, lv_grid_align_t row_align, int32_t row_pos, int32_t row_span);

    private:

  };
}