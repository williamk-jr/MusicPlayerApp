#include "image.h"

namespace iamaprogrammer {
  ImageWidget::ImageWidget(LvObject* parent) :
    LvObject(lv_image_create(parent->getHandle())) {}

  void ImageWidget::setSrc(const void * src) {
    lv_image_set_src(this->getHandle(), src);
  }

  const void * ImageWidget::getSrc() {
    return lv_image_get_src(this->getHandle());
  }
}
