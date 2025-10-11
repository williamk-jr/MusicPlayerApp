#include "widget.h"

namespace iamaprogrammer {

  void Widget::create(lv_obj_t* parent) {
    this->assign(lv_obj_create(parent));
  }


  void Widget::assign(lv_obj_t* object) {
    this->widget = object;
  }


  lv_obj_t* Widget::getHandle() {
    return this->widget;
  }


  void Widget::setPos(int32_t x, int32_t y) {
    lv_obj_set_pos(this->widget, x, y);
  }


  void Widget::setX(int32_t x) {
    lv_obj_set_x(this->widget, x);
  }


  void Widget::setY(int32_t y) {
    lv_obj_set_y(this->widget, y);
  }


  void Widget::setSize(int32_t w, int32_t h) {
    lv_obj_set_size(this->widget, w, h);
  }


  bool Widget::refrSize() {
    return lv_obj_refr_size(this->widget);
  }


  void Widget::setWidth(int32_t w) {
    lv_obj_set_width(this->widget, w);
  }


  void Widget::setHeight(int32_t h) {
    lv_obj_set_height(this->widget, h);
  }


  void Widget::setContentWidth(int32_t w) {
    lv_obj_set_content_width(this->widget, w);
    
  }


  void Widget::setContentHeight(int32_t h) {
    lv_obj_set_content_height(this->widget, h);
  }


  void Widget::setLayout(uint32_t layout) {
    lv_obj_set_layout(this->widget, layout);
  }


  bool Widget::isLayoutPositioned() {
    return lv_obj_is_layout_positioned(this->widget);
  }


  void Widget::markLayoutAsDirty() {
    lv_obj_mark_layout_as_dirty(this->widget);
  }


  void Widget::updateLayout() {
    lv_obj_update_layout(this->widget);
  }


  void Widget::setAlign(lv_align_t align) {
    lv_obj_set_align(this->widget, align);
  }


  void Widget::align(lv_align_t align, int32_t x_ofs, int32_t y_ofs) {
    lv_obj_align(this->widget, align, x_ofs, y_ofs);
  }


  void Widget::alignTo(const lv_obj_t *base, lv_align_t align, int32_t x_ofs, int32_t y_ofs) {
    lv_obj_align_to(this->widget, base, align, x_ofs, y_ofs);
  }


  void Widget::center() {
    lv_obj_center(this->widget);
  }


  void Widget::setTransform(const lv_matrix_t *matrix) {
    lv_obj_set_transform(this->widget, matrix);
  }


  void Widget::resetTransform() {
    lv_obj_reset_transform(this->widget);
  }


  void Widget::getCoords(lv_area_t *coords) {
    lv_obj_get_coords(this->widget, coords);
  }


  int32_t Widget::getX() {
    return lv_obj_get_x(this->widget);
  }


  int32_t Widget::getX2() {
    return lv_obj_get_x2(this->widget);
  }


  int32_t Widget::getY() {
    return lv_obj_get_y(this->widget);
  }


  int32_t Widget::getY2() {
    return lv_obj_get_y2(this->widget);
  }


  int32_t Widget::getXAligned() {
    return lv_obj_get_x_aligned(this->widget);
  }


  int32_t Widget::getYAligned() {
    return lv_obj_get_y_aligned(this->widget);
  }


  int32_t Widget::getWidth() {
    return lv_obj_get_width(this->widget);
  }


  int32_t Widget::getHeight() {
    return lv_obj_get_height(this->widget);
  }


  int32_t Widget::getContentWidth() {
    return lv_obj_get_content_width(this->widget);
  }


  int32_t Widget::getContentHeight() {
    return lv_obj_get_content_height(this->widget);
  }


  void Widget::getContentCoords(lv_area_t *area) {
    lv_obj_get_content_coords(this->widget, area);
  }


  int32_t Widget::getSelfWidth() {
    return lv_obj_get_self_width(this->widget);
  }


  int32_t Widget::getSelfHeight() {
    return lv_obj_get_self_height(this->widget);
  }


  bool Widget::refreshSelfSize() {
    return lv_obj_refresh_self_size(this->widget);
  }


  void Widget::refrPos() {
    lv_obj_refr_pos(this->widget);
  }


  void Widget::moveTo(int32_t x, int32_t y) {
    lv_obj_move_to(this->widget, x, y);
  }


  void Widget::moveChildrenBy(int32_t x_diff, int32_t y_diff, bool ignore_floating) {
    lv_obj_move_children_by(this->widget, x_diff, y_diff, ignore_floating);
  }


  // const lv_matrix_t *getTransform() {
  //   return lv_obj_get_transform(this->widget);
  // }


  void Widget::transformPoint(lv_point_t *p, lv_obj_point_transform_flag_t flags) {
    lv_obj_transform_point(this->widget, p, flags);
  }


  void Widget::transformPointArray(lv_point_t points[], size_t count, lv_obj_point_transform_flag_t flags) {
    lv_obj_transform_point_array(this->widget, points, count, flags);
  }


  void Widget::getTransformedArea(lv_area_t *area, lv_obj_point_transform_flag_t flags) {
    lv_obj_get_transformed_area(this->widget, area, flags);
  }


  void Widget::invalidateArea(const lv_area_t *area) {
    lv_obj_invalidate_area(this->widget, area);
  }


  void Widget::invalidate() {
    lv_obj_invalidate(this->widget);
  }


  bool Widget::areaIsVisible(lv_area_t *area) {
    return lv_obj_area_is_visible(this->widget, area);
  }


  bool Widget::isVisible() {
    return lv_obj_is_visible(this->widget);
  }


  void Widget::setExtClickArea(int32_t size) {
    lv_obj_set_ext_click_area(this->widget, size);
  }


  void Widget::getClickArea(lv_area_t *area) {
    lv_obj_get_click_area(this->widget, area);
  }


  bool Widget::hitTest(const lv_point_t *point) {
    return lv_obj_hit_test(this->widget, point);
  }

  // Styling
  void Widget::addStyle(Style* style, lv_style_selector_t selector) {
    lv_obj_add_style(this->widget, style->getHandle(), selector);
  }


  // Events
}