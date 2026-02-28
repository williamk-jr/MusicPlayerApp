#include "animimage.h"

namespace iamaprogrammer {
  AnimImageWidget::AnimImageWidget(LvObject* parent) :
    LvObject(lv_animimg_create(parent->getHandle())) {}

  void AnimImageWidget::setSrc(const void ** dsc, size_t num) {
    lv_animimg_set_src(this->getHandle(), dsc, num);
  }

  void AnimImageWidget::start() {
    lv_animimg_start(this->getHandle());
  }

  void AnimImageWidget::setDuration(uint32_t d) {
    lv_animimg_set_duration(this->getHandle(), d);
  }

  uint32_t AnimImageWidget::getDuration() {
    return lv_animimg_get_duration(this->getHandle());
  }
}
