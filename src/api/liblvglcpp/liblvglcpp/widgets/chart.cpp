#include "chart.h"

namespace iamaprogrammer {
  ChartWidget::ChartWidget(LvObject* parent) :
    LvObject(lv_chart_create(parent->getHandle())) {}

  lv_chart_series_t* ChartWidget::addSeries(lv_color_t color, lv_chart_axis_t axis) {
    return lv_chart_add_series(this->getHandle(), color, axis);
  }

  void ChartWidget::setPointCount(uint16_t cnt) {
    lv_chart_set_point_count(this->getHandle(), cnt);
  }

  void ChartWidget::addPoint(lv_chart_series_t* series, int32_t v) {
    lv_chart_set_next_value(this->getHandle(), series, v);
  }

  void ChartWidget::setAxisRange(lv_chart_axis_t axis, int32_t min, int32_t max) {
    lv_chart_set_axis_range(this->getHandle(), axis, min, max);
  }
}
