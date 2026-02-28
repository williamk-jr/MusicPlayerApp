#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ImageWidget: public LvObject {
    public:
      ImageWidget(LvObject* parent);

      void setSrc(const void * src);
      const void * getSrc();
  };
}
