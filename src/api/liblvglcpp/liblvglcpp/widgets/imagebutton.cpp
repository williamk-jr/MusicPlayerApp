#include "imagebutton.h"

namespace iamaprogrammer {
  ImageButtonWidget::ImageButtonWidget(LvObject* parent) :
    LvObject(lv_imgbtn_create(parent->getHandle())) {}

  void ImageButtonWidget::setSrc(const char* src) {
    //lv_imagebutton_set_src(this->getHandle(), LV_IMGBTN_STATE_RELEASED, src);
  }
}
