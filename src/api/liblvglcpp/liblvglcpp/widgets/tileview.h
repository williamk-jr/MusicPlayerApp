#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class TileViewWidget: public LvObject {
    public:
      TileViewWidget(LvObject* parent);

      void addTile(lv_coord_t x, lv_coord_t y, lv_dir_t dir);
  };
}
