#pragma once
#include <iostream>
#include <vector>

#include "../../event/event_bus.h"
#include "registry/src/registry/registry.h"

#include <liblvglcpp/lvgl_cpp.h>

#include <src/app/state/application_model.h>

namespace iamaprogrammer {
  class Page {
    public:
      Page(ApplicationModel& applicationModel);
      Page(ApplicationModel& applicationModel, std::vector<int32_t> columns, std::vector<int32_t> rows);
      virtual void init(lv_display_t* disp) = 0;

      virtual void setVisible(bool visible) final;
      virtual bool isVisible() final;
      virtual Grid& getPageGrid() final;


    protected:
      std::vector<int32_t> grid_columns;
      std::vector<int32_t> grid_rows;
      Grid grid;

      ApplicationModel& applicationModel;
  };
}