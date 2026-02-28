#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class ChartWidget: public LvObject {
    public:
      ChartWidget(LvObject* parent);

      lv_chart_series_t* addSeries(lv_color_t color, lv_chart_axis_t axis);
      void setPointCount(uint16_t cnt);
      void addPoint(lv_chart_series_t* series, int32_t v);
      void setAxisRange(lv_chart_axis_t axis, int32_t min, int32_t max);
  };
}
