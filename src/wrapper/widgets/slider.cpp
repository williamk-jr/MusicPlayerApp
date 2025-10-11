#include "slider.h"
namespace iamaprogrammer {
  SliderWidget::SliderWidget(Widget* parent) {
    this->create(parent->getHandle());
  }

  SliderWidget::SliderWidget(lv_obj_t* parent) {
    this->create(parent);
  }
  
  void SliderWidget::create(lv_obj_t* parent) {
    this->assign(
      lv_slider_create(parent)
    );
  }


  void SliderWidget::setValue(int32_t value, lv_anim_enable_t anim) {
    lv_slider_set_value(this->getHandle(), value, anim);
  }

  void SliderWidget::setStartValue(int32_t value, lv_anim_enable_t anim) {
    lv_slider_set_start_value(this->getHandle(), value, anim);
  }

  void SliderWidget::setRange(int32_t min, int32_t max) {
    lv_slider_set_range(this->getHandle(), min, max);
  }

  void SliderWidget::setMode(lv_slider_mode_t mode) {
    lv_slider_set_mode(this->getHandle(), mode);
  }

  void SliderWidget::setOrientation(lv_slider_orientation_t orientation) {
    lv_slider_set_orientation(this->getHandle(), orientation);
  }

  int32_t SliderWidget::getValue() {
    return lv_slider_get_value(this->getHandle());
  }

  int32_t SliderWidget::getLeftValue() {
    return lv_slider_get_left_value(this->getHandle());
  }

  int32_t SliderWidget::getMinValue() {
    return lv_slider_get_min_value(this->getHandle());
  }

  int32_t SliderWidget::getMaxValue() {
    return lv_slider_get_max_value(this->getHandle());
  }

  bool SliderWidget::isDragged() {
    return lv_slider_is_dragged(this->getHandle());
  }

  lv_slider_mode_t SliderWidget::getMode() {
    return lv_slider_get_mode(this->getHandle());
  }

  lv_slider_orientation_t SliderWidget::getOrientation() {
    return lv_slider_get_orientation(this->getHandle());
  }

  bool SliderWidget::isSymmetrical() {
    return lv_slider_is_symmetrical(this->getHandle());
  }

  lv_observer_t* SliderWidget::bindValue(lv_subject_t *subject) {
    return lv_slider_bind_value(this->getHandle(), subject);
  }
}