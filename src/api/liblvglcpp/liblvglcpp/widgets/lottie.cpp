#include "lottie.h"

namespace iamaprogrammer {
  LottieWidget::LottieWidget(LvObject* parent) :
    LvObject(lv_lottie_create(parent->getHandle())) {}

  void LottieWidget::setSrcFile(const char* file) {
    lv_lottie_set_src_file(this->getHandle(), file);
  }

  void LottieWidget::setBuffer(int32_t w, int32_t h, void* buf) {
    lv_lottie_set_buffer(this->getHandle(), w, h, buf);
  }
}
