#include "style.h"

namespace iamaprogrammer {

  Style::Style() {
    lv_style_init(&this->style);
  }

  const lv_style_t* Style::getHandle() {
    return &this->style;
  }

  lv_style_t* Style::create() {
    return &this->style;
  }
  
  Style& Style::width(int32_t value) {
    return *this;
  }

  Style& Style::minWidth(int32_t value) {
    return *this;
  }

  Style& Style::maxWidth(int32_t value) {
    return *this;
  }

  Style& Style::height(int32_t value) {
    return *this;
  }

  Style& Style::minHeight(int32_t value) {
    return *this;
  }

  Style& Style::maxHeight(int32_t value) {
    return *this;
  }

  Style& Style::length(int32_t value) {
    return *this;
  }

  Style& Style::x(int32_t value) {
    return *this;
  }

  Style& Style::y(int32_t value) {
    return *this;
  }

  Style& Style::align(lv_align_t value) {
    return *this;
  }

  Style& Style::transformWidth(int32_t value) {
    return *this;
  }

  Style& Style::transformHeight(int32_t value) {
    return *this;
  }

  Style& Style::translateX(int32_t value) {
    return *this;
  }

  Style& Style::translateY(int32_t value) {
    return *this;
  }

  Style& Style::translateRadial(int32_t value) {
    return *this;
  }

  Style& Style::transformScaleX(int32_t value) {
    return *this;
  }

  Style& Style::transformScaleY(int32_t value) {
    return *this;
  }

  Style& Style::transformRotation(int32_t value) {
    return *this;
  }

  Style& Style::transformPivotX(int32_t value) {
    return *this;
  }

  Style& Style::transformPivotY(int32_t value) {
    return *this;
  }

  Style& Style::transformSkewX(int32_t value) {
    return *this;
  }

  Style& Style::transformSkewY(int32_t value) {
    return *this;
  }

  Style& Style::padTop(int32_t value) {
    return *this;
  }

  Style& Style::padBottom(int32_t value) {
    return *this;
  }

  Style& Style::padLeft(int32_t value) {
    return *this;
  }

  Style& Style::padRight(int32_t value) {
    return *this;
  }

  Style& Style::padRow(int32_t value) {
    return *this;
  }

  Style& Style::padColumn(int32_t value) {
    return *this;
  }

  Style& Style::padRadial(int32_t value) {
    return *this;
  }

  Style& Style::marginTop(int32_t value) {
    return *this;
  }

  Style& Style::marginBottom(int32_t value) {
    return *this;
  }

  Style& Style::marginLeft(int32_t value) {
    return *this;
  }

  Style& Style::marginRight(int32_t value) {
    return *this;
  }

  Style& Style::backgroundColor(lv_color_t color) {
    lv_style_set_bg_color(&this->style, color);
    return *this;
  }

  Style& Style::backgroundOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::backgroundGradColor(lv_color_t value) {
    return *this;
  }

  Style& Style::backgroundGradDir(lv_grad_dir_t value) {
    return *this;
  }

  Style& Style::backgroundMainStop(int32_t value) {
    return *this;
  }

  Style& Style::backgroundGradStop(int32_t value) {
    return *this;
  }

  Style& Style::backgroundMainOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::backgroundGradOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::backgroundGrad(const lv_grad_dsc_t *value) {
    return *this;
  }

  Style& Style::backgroundImageSrc(const void *value) {
    return *this;
  }

  Style& Style::backgroundImageOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::backgroundImageRecolor(lv_color_t value) {
    return *this;
  }

  Style& Style::backgroundImageRecolorOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::backgroundImageTiled(bool value) {
    return *this;
  }

  Style& Style::borderColor(lv_color_t value) {
    return *this;
  }

  Style& Style::borderOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::borderWidth(int32_t value) {
    return *this;
  }

  Style& Style::borderSide(lv_border_side_t value) {
    return *this;
  }

  Style& Style::borderPost(bool value) {
    return *this;
  }

  Style& Style::outlineWidth(int32_t value) {
    return *this;
  }

  Style& Style::outlineColor(lv_color_t value) {
    return *this;
  }

  Style& Style::outlineOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::outlinePad(int32_t value) {
    return *this;
  }

  Style& Style::shadowWidth(int32_t value) {
    return *this;
  }

  Style& Style::shadowOffsetX(int32_t value) {
    return *this;
  }

  Style& Style::shadowOffsetY(int32_t value) {
    return *this;
  }

  Style& Style::shadowSpread(int32_t value) {
    return *this;
  }

  Style& Style::shadowColor(lv_color_t value) {
    return *this;
  }

  Style& Style::shadowOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::imageOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::imageRecolor(lv_color_t value) {
    return *this;
  }

  Style& Style::imageRecolorOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::lineWidth(int32_t value) {
    return *this;
  }

  Style& Style::lineDashWidth(int32_t value) {
    return *this;
  }

  Style& Style::lineDashGap(int32_t value) {
    return *this;
  }

  Style& Style::lineRounded(bool value) {
    return *this;
  }

  Style& Style::lineColor(lv_color_t value) {
    return *this;
  }

  Style& Style::lineOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::arcWidth(int32_t value) {
    return *this;
  }

  Style& Style::arcRounded(bool value) {
    return *this;
  }

  Style& Style::arcColor(lv_color_t value) {
    return *this;
  }

  Style& Style::arcOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::arcImageSrc(const void *value) {
    return *this;
  }

  Style& Style::textColor(lv_color_t value) {
    return *this;
  }

  Style& Style::textOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::textFont(const lv_font_t *value) {
    return *this;
  }

  Style& Style::textLetterSpace(int32_t value) {
    return *this;
  }

  Style& Style::textLineSpace(int32_t value) {
    return *this;
  }

  Style& Style::textDecor(lv_text_decor_t value) {
    return *this;
  }

  Style& Style::textAlign(lv_text_align_t value) {
    return *this;
  }

  Style& Style::textOutlineStrokeColor(lv_color_t value) {
    return *this;
  }

  Style& Style::textOutlineStrokeWidth(int32_t value) {
    return *this;
  }

  Style& Style::textOutlineStrokeOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::radius(int32_t value) {
    lv_style_set_radius(&this->style, value);
    return *this;
  }

  Style& Style::radialOffset(int32_t value) {
    return *this;
  }

  Style& Style::clipCorner(bool value) {
    return *this;
  }

  Style& Style::opacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::opacityLayered(lv_opa_t value) {
    return *this;
  }

  Style& Style::colorFilterDsc(const lv_color_filter_dsc_t *value) {
    return *this;
  }

  Style& Style::colorFilterOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::recolor(lv_color_t value) {
    return *this;
  }

  Style& Style::recolorOpacity(lv_opa_t value) {
    return *this;
  }

  Style& Style::anim(const lv_anim_t *value) {
    return *this;
  }

  Style& Style::animDuration(uint32_t value) {
    return *this;
  }

  Style& Style::transition(const lv_style_transition_dsc_t *value) {
    return *this;
  }

  Style& Style::blendMode(lv_blend_mode_t value) {
    return *this;
  }

  Style& Style::layout(uint16_t value) {
    return *this;
  }

  Style& Style::baseDir(lv_base_dir_t value) {
    return *this;
  }

  Style& Style::bitmapMaskSrc(const void *value) {
    return *this;
  }

  Style& Style::rotarySensitivity(uint32_t value) {
    return *this;
  }
}