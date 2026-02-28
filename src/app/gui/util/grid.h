#pragma once
#include <vector>
#include <iostream>

extern "C" {
  #include "lvgl/lvgl.h"
}

#include "style.h"

namespace iamaprogrammer {
  lv_obj_t* lvext_grid_create(lv_obj_t* parent, const std::vector<int32_t>& columns, const std::vector<int32_t>& rows);

  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, lv_grid_align_t column_align, int32_t col_pos, int32_t col_span, lv_grid_align_t row_align, int32_t row_pos, int32_t row_span);
  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, lv_grid_align_t column_align, int32_t col_pos, lv_grid_align_t row_align, int32_t row_pos);
  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, int32_t col_pos, int32_t col_span, int32_t row_pos, int32_t row_span);
  lv_obj_t* lvext_grid_cell_create(lv_obj_t* parent, int32_t col_pos, int32_t row_pos);
}