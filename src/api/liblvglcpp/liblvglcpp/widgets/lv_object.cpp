#include "lv_object.h"

namespace iamaprogrammer {

  LvObject::LvObject(lv_obj_t* obj) : widget(obj), initialized(true) {
    lv_obj_set_style_pad_all(obj, 0, 0);
    lv_obj_set_style_radius(obj, 0, 0);
  }

  LvObject::LvObject(LvObject&& other) noexcept : widget(other.widget), initialized(true) {
    other.widget = nullptr;
  }

  LvObject& LvObject::operator=(LvObject&& other) noexcept {
    if (this != &other) {
        this->widget = other.widget;
        other.widget = nullptr;
    }
    return *this;
  }

  // LvObject::~LvObject() {
  //   lv_obj_delete(this->widget);
  // }

  // void LvObject::create(lv_obj_t* parent) {
  //   this->assign(lv_obj_create(parent));
  // }


  // void LvObject::assign(lv_obj_t* object) {
  //   this->widget = object;

  //   // Remove unwanted default styles
  //   this->setStylePadLeft(0, 0);
  //   this->setStylePadRight(0, 0);
  //   this->setStylePadTop(0, 0);
  //   this->setStylePadBottom(0, 0);

  //   this->setStyleRadius(0, 0);
  // }


  lv_obj_t* LvObject::getHandle() {
    return this->widget;
  }

  void LvObject::setFlag(lv_obj_flag_t f, bool v) {
    lv_obj_set_flag(this->widget, f, v);
  }

  bool LvObject::hasFlag(lv_obj_flag_t f) {
    return lv_obj_has_flag(this->widget, f);
  }


  void LvObject::setPos(int32_t x, int32_t y) {
    lv_obj_set_pos(this->widget, x, y);
  }


  void LvObject::setX(int32_t x) {
    lv_obj_set_x(this->widget, x);
  }


  void LvObject::setY(int32_t y) {
    lv_obj_set_y(this->widget, y);
  }


  void LvObject::setSize(int32_t w, int32_t h) {
    lv_obj_set_size(this->widget, w, h);
  }


  bool LvObject::refrSize() {
    return lv_obj_refr_size(this->widget);
  }


  void LvObject::setWidth(int32_t w) {
    lv_obj_set_width(this->widget, w);
  }


  void LvObject::setHeight(int32_t h) {
    lv_obj_set_height(this->widget, h);
  }


  void LvObject::setContentWidth(int32_t w) {
    lv_obj_set_content_width(this->widget, w);
    
  }


  void LvObject::setContentHeight(int32_t h) {
    lv_obj_set_content_height(this->widget, h);
  }


  void LvObject::setLayout(uint32_t layout) {
    lv_obj_set_layout(this->widget, layout);
  }


  bool LvObject::isLayoutPositioned() {
    return lv_obj_is_layout_positioned(this->widget);
  }


  void LvObject::markLayoutAsDirty() {
    lv_obj_mark_layout_as_dirty(this->widget);
  }


  void LvObject::updateLayout() {
    lv_obj_update_layout(this->widget);
  }


  void LvObject::setAlign(lv_align_t align) {
    lv_obj_set_align(this->widget, align);
  }


  void LvObject::align(lv_align_t align, int32_t x_ofs, int32_t y_ofs) {
    lv_obj_align(this->widget, align, x_ofs, y_ofs);
  }


  void LvObject::alignTo(const lv_obj_t *base, lv_align_t align, int32_t x_ofs, int32_t y_ofs) {
    lv_obj_align_to(this->widget, base, align, x_ofs, y_ofs);
  }


  void LvObject::center() {
    lv_obj_center(this->widget);
  }


  void LvObject::setTransform(const lv_matrix_t *matrix) {
    lv_obj_set_transform(this->widget, matrix);
  }


  void LvObject::resetTransform() {
    lv_obj_reset_transform(this->widget);
  }


  void LvObject::getCoords(lv_area_t *coords) {
    lv_obj_get_coords(this->widget, coords);
  }


  int32_t LvObject::getX() {
    return lv_obj_get_x(this->widget);
  }


  int32_t LvObject::getX2() {
    return lv_obj_get_x2(this->widget);
  }


  int32_t LvObject::getY() {
    return lv_obj_get_y(this->widget);
  }


  int32_t LvObject::getY2() {
    return lv_obj_get_y2(this->widget);
  }


  int32_t LvObject::getXAligned() {
    return lv_obj_get_x_aligned(this->widget);
  }


  int32_t LvObject::getYAligned() {
    return lv_obj_get_y_aligned(this->widget);
  }


  int32_t LvObject::getWidth() {
    return lv_obj_get_width(this->widget);
  }


  int32_t LvObject::getHeight() {
    return lv_obj_get_height(this->widget);
  }


  int32_t LvObject::getContentWidth() {
    return lv_obj_get_content_width(this->widget);
  }


  int32_t LvObject::getContentHeight() {
    return lv_obj_get_content_height(this->widget);
  }


  void LvObject::getContentCoords(lv_area_t *area) {
    lv_obj_get_content_coords(this->widget, area);
  }


  int32_t LvObject::getSelfWidth() {
    return lv_obj_get_self_width(this->widget);
  }


  int32_t LvObject::getSelfHeight() {
    return lv_obj_get_self_height(this->widget);
  }


  bool LvObject::refreshSelfSize() {
    return lv_obj_refresh_self_size(this->widget);
  }


  void LvObject::refrPos() {
    lv_obj_refr_pos(this->widget);
  }


  void LvObject::moveTo(int32_t x, int32_t y) {
    lv_obj_move_to(this->widget, x, y);
  }


  void LvObject::moveChildrenBy(int32_t x_diff, int32_t y_diff, bool ignore_floating) {
    lv_obj_move_children_by(this->widget, x_diff, y_diff, ignore_floating);
  }


  // const lv_matrix_t *getTransform() {
  //   return lv_obj_get_transform(this->widget);
  // }


  void LvObject::transformPoint(lv_point_t *p, lv_obj_point_transform_flag_t flags) {
    lv_obj_transform_point(this->widget, p, flags);
  }


  void LvObject::transformPointArray(lv_point_t points[], size_t count, lv_obj_point_transform_flag_t flags) {
    lv_obj_transform_point_array(this->widget, points, count, flags);
  }


  void LvObject::getTransformedArea(lv_area_t *area, lv_obj_point_transform_flag_t flags) {
    lv_obj_get_transformed_area(this->widget, area, flags);
  }


  void LvObject::invalidateArea(const lv_area_t *area) {
    lv_obj_invalidate_area(this->widget, area);
  }


  void LvObject::invalidate() {
    lv_obj_invalidate(this->widget);
  }


  bool LvObject::areaIsVisible(lv_area_t *area) {
    return lv_obj_area_is_visible(this->widget, area);
  }


  bool LvObject::isVisible() {
    return lv_obj_is_visible(this->widget);
  }


  void LvObject::setExtClickArea(int32_t size) {
    lv_obj_set_ext_click_area(this->widget, size);
  }


  void LvObject::getClickArea(lv_area_t *area) {
    lv_obj_get_click_area(this->widget, area);
  }


  bool LvObject::hitTest(const lv_point_t *point) {
    return lv_obj_hit_test(this->widget, point);
  }

  // Styling
  void LvObject::addStyle(Style* style, lv_style_selector_t selector) {
    lv_obj_add_style(this->widget, style->getHandle(), selector);
  }

  void LvObject::addEventCallback(lv_event_cb_t event_cb, lv_event_code_t filter, void* user_data) {
    lv_obj_add_event_cb(this->widget, event_cb, filter, user_data);
  }

  void LvObject::sendEvent(uint32_t event_code, void* param) {
    lv_obj_send_event(this->widget, (lv_event_code_t)event_code, nullptr);
  }

  void LvObject::setStyleWidth(int32_t value, lv_style_selector_t selector) {
    lv_obj_set_style_width(this->widget, value, selector);
  }
  void LvObject::setStyleMinWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_min_width(this->widget, value, selector);
  }
  void LvObject::setStyleMaxWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_max_width(this->widget, value, selector);
  }
  void LvObject::setStyleHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_height(this->widget, value, selector);
  }
  void LvObject::setStyleMinHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_min_height(this->widget, value, selector);
  }
  void LvObject::setStyleMaxHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_max_height(this->widget, value, selector);
  }
  void LvObject::setStyleLength(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_length(this->widget, value, selector);
  }
  void LvObject::setStyleX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_x(this->widget, value, selector);
  }
  void LvObject::setStyleY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_y(this->widget, value, selector);
  }
  void LvObject::setStyleAlign(lv_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_align(this->widget, value, selector);
  }
  void LvObject::setStyleTransformWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_width(this->widget, value, selector);
  }
  void LvObject::setStyleTransformHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_height(this->widget, value, selector);
  }
  void LvObject::setStyleTranslateX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_x(this->widget, value, selector);
  }
  void LvObject::setStyleTranslateY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_y(this->widget, value, selector);
  }
  void LvObject::setStyleTranslateRadial(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_radial(this->widget, value, selector);
  }
  void LvObject::setStyleTransformScaleX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_scale_x(this->widget, value, selector);
  }
  void LvObject::setStyleTransformScaleY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_scale_y(this->widget, value, selector);
  }
  void LvObject::setStyleTransformRotation(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_rotation(this->widget, value, selector);
  }
  void LvObject::setStyleTransformPivotX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_pivot_x(this->widget, value, selector);
  }
  void LvObject::setStyleTransformPivotY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_pivot_y(this->widget, value, selector);
  }
  void LvObject::setStyleTransformSkewX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_skew_x(this->widget, value, selector);
  }
  void LvObject::setStyleTransformSkewY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_skew_y(this->widget, value, selector);
  }
  void LvObject::setStylePadTop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_top(this->widget, value, selector);
  }
  void LvObject::setStylePadBottom(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_bottom(this->widget, value, selector);
  }
  void LvObject::setStylePadLeft(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_left(this->widget, value, selector);
  }
  void LvObject::setStylePadRight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_right(this->widget, value, selector);
  }
  void LvObject::setStylePadRow(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_row(this->widget, value, selector);
  }
  void LvObject::setStylePadColumn(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_column(this->widget, value, selector);
  }
  void LvObject::setStylePadRadial(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_radial(this->widget, value, selector);
  }
  void LvObject::setStyleMarginTop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_top(this->widget, value, selector);
  }
  void LvObject::setStyleMarginBottom(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_bottom(this->widget, value, selector);
  }
  void LvObject::setStyleMarginLeft(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_left(this->widget, value, selector);
  }
  void LvObject::setStyleMarginRight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_right(this->widget, value, selector);
  }
  void LvObject::setStyleBgColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_color(this->widget, value, selector);
  }
  void LvObject::setStyleBgOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBgGradColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_color(this->widget, value, selector);
  }
  void LvObject::setStyleBgGradDir(lv_grad_dir_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_dir(this->widget, value, selector);
  }
  void LvObject::setStyleBgMainStop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_main_stop(this->widget, value, selector);
  }
  void LvObject::setStyleBgGradStop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_stop(this->widget, value, selector);
  }
  void LvObject::setStyleBgMainOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_main_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBgGradOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBgGrad(const lv_grad_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad(this->widget, value, selector);
  }
  void LvObject::setStyleBgImageSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_src(this->widget, value, selector);
  }
  void LvObject::setStyleBgImageOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBgImageRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_recolor(this->widget, value, selector);
  }
  void LvObject::setStyleBgImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_recolor_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBgImageTiled(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_tiled(this->widget, value, selector);
  }
  void LvObject::setStyleBorderColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_color(this->widget, value, selector);
  }
  void LvObject::setStyleBorderOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_opa(this->widget, value, selector);
  }
  void LvObject::setStyleBorderWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_width(this->widget, value, selector);
  }
  void LvObject::setStyleBorderSide(lv_border_side_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_side(this->widget, value, selector);
  }
  void LvObject::setStyleBorderPost(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_border_post(this->widget, value, selector);
  }
  void LvObject::setStyleOutlineWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_width(this->widget, value, selector);
  }
  void LvObject::setStyleOutlineColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_color(this->widget, value, selector);
  }
  void LvObject::setStyleOutlineOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_opa(this->widget, value, selector);
  }
  void LvObject::setStyleOutlinePad(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_pad(this->widget, value, selector);
  }
  void LvObject::setStyleShadowWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_width(this->widget, value, selector);
  }
  void LvObject::setStyleShadowOffsetX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_offset_x(this->widget, value, selector);
  }
  void LvObject::setStyleShadowOffsetY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_offset_y(this->widget, value, selector);
  }
  void LvObject::setStyleShadowSpread(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_spread(this->widget, value, selector);
  }
  void LvObject::setStyleShadowColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_color(this->widget, value, selector);
  }
  void LvObject::setStyleShadowOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_opa(this->widget, value, selector);
  }
  void LvObject::setStyleImageOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_opa(this->widget, value, selector);
  }
  void LvObject::setStyleImageRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_recolor(this->widget, value, selector);
  }
  void LvObject::setStyleImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_recolor_opa(this->widget, value, selector);
  }
  void LvObject::setStyleLineWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_width(this->widget, value, selector);
  }
  void LvObject::setStyleLineDashWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_dash_width(this->widget, value, selector);
  }
  void LvObject::setStyleLineDashGap(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_dash_gap(this->widget, value, selector);
  }
  void LvObject::setStyleLineRounded(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_line_rounded(this->widget, value, selector);
  }
  void LvObject::setStyleLineColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_color(this->widget, value, selector);
  }
  void LvObject::setStyleLineOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_opa(this->widget, value, selector);
  }
  void LvObject::setStyleArcWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_width(this->widget, value, selector);
  }
  void LvObject::setStyleArcRounded(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_rounded(this->widget, value, selector);
  }
  void LvObject::setStyleArcColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_color(this->widget, value, selector);
  }
  void LvObject::setStyleArcOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_opa(this->widget, value, selector);
  }
  void LvObject::setStyleArcImageSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_image_src(this->widget, value, selector);
  }
  void LvObject::setStyleTextColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_color(this->widget, value, selector);
  }
  void LvObject::setStyleTextOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_opa(this->widget, value, selector);
  }
  void LvObject::setStyleTextFont(const lv_font_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_text_font(this->widget, value, selector);
  }
  void LvObject::setStyleTextLetterSpace(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_letter_space(this->widget, value, selector);
  }
  void LvObject::setStyleTextLineSpace(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_line_space(this->widget, value, selector);
  }
  void LvObject::setStyleTextDecor(lv_text_decor_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_decor(this->widget, value, selector);
  }
  void LvObject::setStyleTextAlign(lv_text_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_align(this->widget, value, selector);
  }
  void LvObject::setStyleTextOutlineStrokeColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_color(this->widget, value, selector);
  }
  void LvObject::setStyleTextOutlineStrokeWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_width(this->widget, value, selector);
  }
  void LvObject::setStyleTextOutlineStrokeOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_opa(this->widget, value, selector);
  }
  void LvObject::setStyleRadius(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_radius(this->widget, value, selector);
  }
  void LvObject::setStyleRadialOffset(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_radial_offset(this->widget, value, selector);
  }
  void LvObject::setStyleClipCorner(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_clip_corner(this->widget, value, selector);
  }
  void LvObject::setStyleOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_opa(this->widget, value, selector);
  }
  void LvObject::setStyleOpaLayered(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_opa_layered(this->widget, value, selector);
  }
  void LvObject::setStyleColorFilterDsc(const lv_color_filter_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_color_filter_dsc(this->widget, value, selector);
  }
  void LvObject::setStyleColorFilterOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_color_filter_opa(this->widget, value, selector);
  }
  void LvObject::setStyleRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_recolor(this->widget, value, selector);
  }
  void LvObject::setStyleRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_recolor_opa(this->widget, value, selector);
  }
  void LvObject::setStyleAnim(const lv_anim_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_anim(this->widget, value, selector);
  }
  void LvObject::setStyleAnimDuration(uint32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_anim_duration(this->widget, value, selector);
  }
  void LvObject::setStyleTransition(const lv_style_transition_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_transition(this->widget, value, selector);
  }
  void LvObject::setStyleBlendMode(lv_blend_mode_t value, lv_style_selector_t selector) {
      lv_obj_set_style_blend_mode(this->widget, value, selector);
  }
  void LvObject::setStyleLayout(uint16_t value, lv_style_selector_t selector) {
      lv_obj_set_style_layout(this->widget, value, selector);
  }
  void LvObject::setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector) {
      lv_obj_set_style_base_dir(this->widget, value, selector);
  }
  void LvObject::setStyleBitmapMaskSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_bitmap_mask_src(this->widget, value, selector);
  }
  void LvObject::setStyleRotarySensitivity(uint32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_rotary_sensitivity(this->widget, value, selector);
  }

  void LvObject::setStyleFlexFlow(lv_flex_flow_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_flow(this->widget, value, selector);
  }
  void LvObject::setStyleFlexMainPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_main_place(this->widget, value, selector);
  }
  void LvObject::setStyleFlexCrossPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_cross_place(this->widget, value, selector);
  }
  void LvObject::setStyleFlexTrackPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_track_place(this->widget, value, selector);
  }
  void LvObject::setStyleFlexGrow(uint8_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_grow(this->widget, value, selector);
  }

  void LvObject::setStyleGridColumnDscArray(const int32_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_column_dsc_array(this->widget, value, selector);
  }
  void LvObject::setStyleGridColumnAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_column_align(this->widget, value, selector);
  }
  void LvObject::setStyleGridRowDscArray(const int32_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_row_dsc_array(this->widget, value, selector);
  }
  void LvObject::setStyleGridRowAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_row_align(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellColumnPos(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_column_pos(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellXAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_x_align(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellColumnSpan(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_column_span(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellRowPos(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_row_pos(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellYAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_y_align(this->widget, value, selector);
  }
  void LvObject::setStyleGridCellRowSpan(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_row_span(this->widget, value, selector);
  }

  // Events
}