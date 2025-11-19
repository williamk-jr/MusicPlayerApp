#include "widget.h"

namespace iamaprogrammer {

  Widget::~Widget() {
    lv_obj_delete(this->widget);
  }

  void Widget::create(lv_obj_t* parent) {
    this->assign(lv_obj_create(parent));
  }


  void Widget::assign(lv_obj_t* object) {
    this->widget = object;

    // Remove unwanted default styles
    this->setStylePadLeft(0, 0);
    this->setStylePadRight(0, 0);
    this->setStylePadTop(0, 0);
    this->setStylePadBottom(0, 0);

    this->setStyleRadius(0, 0);
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

  void Widget::addEventCallback(lv_event_cb_t event_cb, lv_event_code_t filter, void* user_data) {
    lv_obj_add_event_cb(this->widget, event_cb, filter, user_data);
  }

  void Widget::sendEvent(uint32_t event_code, void* param) {
    lv_obj_send_event(this->widget, (lv_event_code_t)event_code, nullptr);
  }

  void Widget::setStyleWidth(int32_t value, lv_style_selector_t selector) {
    lv_obj_set_style_width(this->widget, value, selector);
  }
  void Widget::setStyleMinWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_min_width(this->widget, value, selector);
  }
  void Widget::setStyleMaxWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_max_width(this->widget, value, selector);
  }
  void Widget::setStyleHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_height(this->widget, value, selector);
  }
  void Widget::setStyleMinHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_min_height(this->widget, value, selector);
  }
  void Widget::setStyleMaxHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_max_height(this->widget, value, selector);
  }
  void Widget::setStyleLength(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_length(this->widget, value, selector);
  }
  void Widget::setStyleX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_x(this->widget, value, selector);
  }
  void Widget::setStyleY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_y(this->widget, value, selector);
  }
  void Widget::setStyleAlign(lv_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_align(this->widget, value, selector);
  }
  void Widget::setStyleTransformWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_width(this->widget, value, selector);
  }
  void Widget::setStyleTransformHeight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_height(this->widget, value, selector);
  }
  void Widget::setStyleTranslateX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_x(this->widget, value, selector);
  }
  void Widget::setStyleTranslateY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_y(this->widget, value, selector);
  }
  void Widget::setStyleTranslateRadial(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_translate_radial(this->widget, value, selector);
  }
  void Widget::setStyleTransformScaleX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_scale_x(this->widget, value, selector);
  }
  void Widget::setStyleTransformScaleY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_scale_y(this->widget, value, selector);
  }
  void Widget::setStyleTransformRotation(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_rotation(this->widget, value, selector);
  }
  void Widget::setStyleTransformPivotX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_pivot_x(this->widget, value, selector);
  }
  void Widget::setStyleTransformPivotY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_pivot_y(this->widget, value, selector);
  }
  void Widget::setStyleTransformSkewX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_skew_x(this->widget, value, selector);
  }
  void Widget::setStyleTransformSkewY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_transform_skew_y(this->widget, value, selector);
  }
  void Widget::setStylePadTop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_top(this->widget, value, selector);
  }
  void Widget::setStylePadBottom(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_bottom(this->widget, value, selector);
  }
  void Widget::setStylePadLeft(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_left(this->widget, value, selector);
  }
  void Widget::setStylePadRight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_right(this->widget, value, selector);
  }
  void Widget::setStylePadRow(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_row(this->widget, value, selector);
  }
  void Widget::setStylePadColumn(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_column(this->widget, value, selector);
  }
  void Widget::setStylePadRadial(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_pad_radial(this->widget, value, selector);
  }
  void Widget::setStyleMarginTop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_top(this->widget, value, selector);
  }
  void Widget::setStyleMarginBottom(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_bottom(this->widget, value, selector);
  }
  void Widget::setStyleMarginLeft(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_left(this->widget, value, selector);
  }
  void Widget::setStyleMarginRight(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_margin_right(this->widget, value, selector);
  }
  void Widget::setStyleBgColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_color(this->widget, value, selector);
  }
  void Widget::setStyleBgOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_opa(this->widget, value, selector);
  }
  void Widget::setStyleBgGradColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_color(this->widget, value, selector);
  }
  void Widget::setStyleBgGradDir(lv_grad_dir_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_dir(this->widget, value, selector);
  }
  void Widget::setStyleBgMainStop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_main_stop(this->widget, value, selector);
  }
  void Widget::setStyleBgGradStop(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_stop(this->widget, value, selector);
  }
  void Widget::setStyleBgMainOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_main_opa(this->widget, value, selector);
  }
  void Widget::setStyleBgGradOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad_opa(this->widget, value, selector);
  }
  void Widget::setStyleBgGrad(const lv_grad_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_grad(this->widget, value, selector);
  }
  void Widget::setStyleBgImageSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_src(this->widget, value, selector);
  }
  void Widget::setStyleBgImageOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_opa(this->widget, value, selector);
  }
  void Widget::setStyleBgImageRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_recolor(this->widget, value, selector);
  }
  void Widget::setStyleBgImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_recolor_opa(this->widget, value, selector);
  }
  void Widget::setStyleBgImageTiled(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_bg_image_tiled(this->widget, value, selector);
  }
  void Widget::setStyleBorderColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_color(this->widget, value, selector);
  }
  void Widget::setStyleBorderOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_opa(this->widget, value, selector);
  }
  void Widget::setStyleBorderWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_width(this->widget, value, selector);
  }
  void Widget::setStyleBorderSide(lv_border_side_t value, lv_style_selector_t selector) {
      lv_obj_set_style_border_side(this->widget, value, selector);
  }
  void Widget::setStyleBorderPost(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_border_post(this->widget, value, selector);
  }
  void Widget::setStyleOutlineWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_width(this->widget, value, selector);
  }
  void Widget::setStyleOutlineColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_color(this->widget, value, selector);
  }
  void Widget::setStyleOutlineOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_opa(this->widget, value, selector);
  }
  void Widget::setStyleOutlinePad(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_outline_pad(this->widget, value, selector);
  }
  void Widget::setStyleShadowWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_width(this->widget, value, selector);
  }
  void Widget::setStyleShadowOffsetX(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_offset_x(this->widget, value, selector);
  }
  void Widget::setStyleShadowOffsetY(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_offset_y(this->widget, value, selector);
  }
  void Widget::setStyleShadowSpread(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_spread(this->widget, value, selector);
  }
  void Widget::setStyleShadowColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_color(this->widget, value, selector);
  }
  void Widget::setStyleShadowOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_shadow_opa(this->widget, value, selector);
  }
  void Widget::setStyleImageOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_opa(this->widget, value, selector);
  }
  void Widget::setStyleImageRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_recolor(this->widget, value, selector);
  }
  void Widget::setStyleImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_image_recolor_opa(this->widget, value, selector);
  }
  void Widget::setStyleLineWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_width(this->widget, value, selector);
  }
  void Widget::setStyleLineDashWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_dash_width(this->widget, value, selector);
  }
  void Widget::setStyleLineDashGap(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_dash_gap(this->widget, value, selector);
  }
  void Widget::setStyleLineRounded(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_line_rounded(this->widget, value, selector);
  }
  void Widget::setStyleLineColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_color(this->widget, value, selector);
  }
  void Widget::setStyleLineOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_line_opa(this->widget, value, selector);
  }
  void Widget::setStyleArcWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_width(this->widget, value, selector);
  }
  void Widget::setStyleArcRounded(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_rounded(this->widget, value, selector);
  }
  void Widget::setStyleArcColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_color(this->widget, value, selector);
  }
  void Widget::setStyleArcOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_opa(this->widget, value, selector);
  }
  void Widget::setStyleArcImageSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_arc_image_src(this->widget, value, selector);
  }
  void Widget::setStyleTextColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_color(this->widget, value, selector);
  }
  void Widget::setStyleTextOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_opa(this->widget, value, selector);
  }
  void Widget::setStyleTextFont(const lv_font_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_text_font(this->widget, value, selector);
  }
  void Widget::setStyleTextLetterSpace(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_letter_space(this->widget, value, selector);
  }
  void Widget::setStyleTextLineSpace(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_line_space(this->widget, value, selector);
  }
  void Widget::setStyleTextDecor(lv_text_decor_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_decor(this->widget, value, selector);
  }
  void Widget::setStyleTextAlign(lv_text_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_align(this->widget, value, selector);
  }
  void Widget::setStyleTextOutlineStrokeColor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_color(this->widget, value, selector);
  }
  void Widget::setStyleTextOutlineStrokeWidth(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_width(this->widget, value, selector);
  }
  void Widget::setStyleTextOutlineStrokeOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_text_outline_stroke_opa(this->widget, value, selector);
  }
  void Widget::setStyleRadius(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_radius(this->widget, value, selector);
  }
  void Widget::setStyleRadialOffset(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_radial_offset(this->widget, value, selector);
  }
  void Widget::setStyleClipCorner(bool value, lv_style_selector_t selector) {
      lv_obj_set_style_clip_corner(this->widget, value, selector);
  }
  void Widget::setStyleOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_opa(this->widget, value, selector);
  }
  void Widget::setStyleOpaLayered(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_opa_layered(this->widget, value, selector);
  }
  void Widget::setStyleColorFilterDsc(const lv_color_filter_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_color_filter_dsc(this->widget, value, selector);
  }
  void Widget::setStyleColorFilterOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_color_filter_opa(this->widget, value, selector);
  }
  void Widget::setStyleRecolor(lv_color_t value, lv_style_selector_t selector) {
      lv_obj_set_style_recolor(this->widget, value, selector);
  }
  void Widget::setStyleRecolorOpa(lv_opa_t value, lv_style_selector_t selector) {
      lv_obj_set_style_recolor_opa(this->widget, value, selector);
  }
  void Widget::setStyleAnim(const lv_anim_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_anim(this->widget, value, selector);
  }
  void Widget::setStyleAnimDuration(uint32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_anim_duration(this->widget, value, selector);
  }
  void Widget::setStyleTransition(const lv_style_transition_dsc_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_transition(this->widget, value, selector);
  }
  void Widget::setStyleBlendMode(lv_blend_mode_t value, lv_style_selector_t selector) {
      lv_obj_set_style_blend_mode(this->widget, value, selector);
  }
  void Widget::setStyleLayout(uint16_t value, lv_style_selector_t selector) {
      lv_obj_set_style_layout(this->widget, value, selector);
  }
  void Widget::setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector) {
      lv_obj_set_style_base_dir(this->widget, value, selector);
  }
  void Widget::setStyleBitmapMaskSrc(const void * value, lv_style_selector_t selector) {
      lv_obj_set_style_bitmap_mask_src(this->widget, value, selector);
  }
  void Widget::setStyleRotarySensitivity(uint32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_rotary_sensitivity(this->widget, value, selector);
  }

  void Widget::setStyleFlexFlow(lv_flex_flow_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_flow(this->widget, value, selector);
  }
  void Widget::setStyleFlexMainPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_main_place(this->widget, value, selector);
  }
  void Widget::setStyleFlexCrossPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_cross_place(this->widget, value, selector);
  }
  void Widget::setStyleFlexTrackPlace(lv_flex_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_track_place(this->widget, value, selector);
  }
  void Widget::setStyleFlexGrow(uint8_t value, lv_style_selector_t selector) {
      lv_obj_set_style_flex_grow(this->widget, value, selector);
  }

  void Widget::setStyleGridColumnDscArray(const int32_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_column_dsc_array(this->widget, value, selector);
  }
  void Widget::setStyleGridColumnAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_column_align(this->widget, value, selector);
  }
  void Widget::setStyleGridRowDscArray(const int32_t * value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_row_dsc_array(this->widget, value, selector);
  }
  void Widget::setStyleGridRowAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_row_align(this->widget, value, selector);
  }
  void Widget::setStyleGridCellColumnPos(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_column_pos(this->widget, value, selector);
  }
  void Widget::setStyleGridCellXAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_x_align(this->widget, value, selector);
  }
  void Widget::setStyleGridCellColumnSpan(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_column_span(this->widget, value, selector);
  }
  void Widget::setStyleGridCellRowPos(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_row_pos(this->widget, value, selector);
  }
  void Widget::setStyleGridCellYAlign(lv_grid_align_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_y_align(this->widget, value, selector);
  }
  void Widget::setStyleGridCellRowSpan(int32_t value, lv_style_selector_t selector) {
      lv_obj_set_style_grid_cell_row_span(this->widget, value, selector);
  }

  // Events
}