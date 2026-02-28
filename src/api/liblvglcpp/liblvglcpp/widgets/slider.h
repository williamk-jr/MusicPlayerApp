#pragma once

#include "lv_object.h"

namespace iamaprogrammer {
  class SliderWidget: public LvObject {
    public:
      SliderWidget() = default;
      SliderWidget(LvObject* parent);

      void setValue(int32_t value, lv_anim_enable_t anim);

      void setStartValue(int32_t value, lv_anim_enable_t anim);

      void setRange(int32_t min, int32_t max);

      void setMode(lv_slider_mode_t mode);

      void setOrientation(lv_slider_orientation_t orientation);

      int32_t getValue();

      int32_t getLeftValue();

      int32_t getMinValue();

      int32_t getMaxValue();

      bool isDragged();

      lv_slider_mode_t getMode();

      lv_slider_orientation_t getOrientation();

      bool isSymmetrical();

      lv_observer_t* bindValue(lv_subject_t *subject);

  };
}