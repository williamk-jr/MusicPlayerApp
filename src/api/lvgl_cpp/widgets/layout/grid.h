#pragma once

#include <vector>
#include "../widget.h"

namespace iamaprogrammer {
  class Grid: public Widget {
    public:
      Grid(Widget* parent, std::vector<int32_t> columns, std::vector<int32_t> rows);
      Grid(lv_obj_t* parent, std::vector<int32_t> columns, std::vector<int32_t> rows);

      void setGridAlign(lv_grid_align_t column_align, lv_grid_align_t row_align);

    private:
      std::vector<int32_t> columns;
      std::vector<int32_t> rows;
  };
}