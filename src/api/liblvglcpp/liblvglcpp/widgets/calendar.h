#pragma once

#include "lv_object.h"
#include <vector>

namespace iamaprogrammer {
  class CalendarWidget: public LvObject {
    public:
      CalendarWidget(LvObject* parent);

      void setTodayDate(uint32_t year, uint32_t month, uint32_t day);
      void setShowedDate(uint32_t year, uint32_t month);
      void setDayNames(const std::vector<const char*>& names);
  };
}
