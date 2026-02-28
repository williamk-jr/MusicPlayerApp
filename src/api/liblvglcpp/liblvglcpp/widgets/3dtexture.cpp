#include "3dtexture.h"

namespace iamaprogrammer {
  Texture3DWidget::Texture3DWidget(LvObject* parent) :
    LvObject(lv_obj_create(parent->getHandle())) {}

  void Texture3DWidget::setSrc(const char* src) {
    // lv_3dtexture_set_src(this->getHandle(), src);
    // lv_3d
  }
}
