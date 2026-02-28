#include "tileview.h"

namespace iamaprogrammer {
  TileViewWidget::TileViewWidget(LvObject* parent) :
    LvObject(lv_tileview_create(parent->getHandle())) {}

  void TileViewWidget::addTile(lv_coord_t x, lv_coord_t y, lv_dir_t dir) {
    lv_tileview_add_tile(this->getHandle(), x, y, dir);
  }
}
