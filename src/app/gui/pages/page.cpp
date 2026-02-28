#include "page.h"

namespace iamaprogrammer {
    Page::Page(ApplicationModel& applicationModel, std::vector<int32_t> columns, std::vector<int32_t> rows) 
      : applicationModel(applicationModel), grid_columns(columns), grid_rows(rows) {}

    Page::Page(ApplicationModel& applicationModel) : applicationModel(applicationModel) {}

    void Page::setVisible(bool visible) {
      this->grid.setFlag(LV_OBJ_FLAG_HIDDEN, !visible);
    }

    bool Page::isVisible() {
      return !this->grid.hasFlag(LV_OBJ_FLAG_HIDDEN);
    }

    Grid& Page::getPageGrid() {
      return this->grid;
    }
}