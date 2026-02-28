#pragma once

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

#include "style/style.h"

#include "widgets/lv_object.h"
#include "widgets/button.h"
#include "widgets/label.h"
#include "widgets/slider.h"
#include "widgets/layout/grid.h"
#include "widgets/layout/grid_cell.h"
#include "widgets/list.h"

#include "lvgl_cpp_util.h"

namespace iamaprogrammer::LvglCpp {
    static void create();
}