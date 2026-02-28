#include "style.h"

namespace iamaprogrammer {
  void lvext_obj_set_style_default(lv_obj_t* obj) {
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_set_style_radius(obj, 0, 0);
  }
}