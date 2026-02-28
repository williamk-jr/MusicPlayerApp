#include "calendar.h"

namespace iamaprogrammer {
  CalendarWidget::CalendarWidget(LvObject* parent) :
    LvObject(lv_calendar_create(parent->getHandle())) {}

  void CalendarWidget::setTodayDate(uint32_t year, uint32_t month, uint32_t day) {
    lv_calendar_set_today_date(this->getHandle(), year, month, day);
  }

  void CalendarWidget::setShowedDate(uint32_t year, uint32_t month) {
    lv_calendar_set_showed_date(this->getHandle(), year, month);
  }

  void CalendarWidget::setDayNames(const std::vector<const char*>& names) {
    std::vector<const char*> n = names;
    n.push_back(nullptr);
    lv_calendar_set_day_names(this->getHandle(), n.data());
  }
}
