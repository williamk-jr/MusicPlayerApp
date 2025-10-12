#pragma once

extern "C" {
  #include "lvgl/lvgl.h"
}

namespace iamaprogrammer {
  class Style {
    public:
      Style();

      lv_style_t* create();

      const lv_style_t* getHandle();
      
      Style& width(int32_t value);

      Style& minWidth(int32_t value);

      Style& maxWidth(int32_t value);

      Style& height(int32_t value);

      Style& minHeight(int32_t value);

      Style& maxHeight(int32_t value);

      Style& length(int32_t value);

      Style& x(int32_t value);

      Style& y(int32_t value);

      Style& align(lv_align_t value);

      Style& transformWidth(int32_t value);

      Style& transformHeight(int32_t value);

      Style& translateX(int32_t value);

      Style& translateY(int32_t value);

      Style& translateRadial(int32_t value);

      Style& transformScaleX(int32_t value);

      Style& transformScaleY(int32_t value);

      Style& transformRotation(int32_t value);

      Style& transformPivotX(int32_t value);

      Style& transformPivotY(int32_t value);

      Style& transformSkewX(int32_t value);

      Style& transformSkewY(int32_t value);

      Style& padTop(int32_t value);

      Style& padBottom(int32_t value);

      Style& padLeft(int32_t value);

      Style& padRight(int32_t value);

      Style& padRow(int32_t value);

      Style& padColumn(int32_t value);

      Style& padRadial(int32_t value);

      Style& marginTop(int32_t value);

      Style& marginBottom(int32_t value);

      Style& marginLeft(int32_t value);

      Style& marginRight(int32_t value);

      Style& backgroundColor(lv_color_t value);

      Style& backgroundOpacity(lv_opa_t value);

      Style& backgroundGradColor(lv_color_t value);

      Style& backgroundGradDir(lv_grad_dir_t value);

      Style& backgroundMainStop(int32_t value);

      Style& backgroundGradStop(int32_t value);

      Style& backgroundMainOpacity(lv_opa_t value);

      Style& backgroundGradOpacity(lv_opa_t value);

      Style& backgroundGrad(const lv_grad_dsc_t *value);

      Style& backgroundImageSrc(const void *value);

      Style& backgroundImageOpacity(lv_opa_t value);

      Style& backgroundImageRecolor(lv_color_t value);

      Style& backgroundImageRecolorOpacity(lv_opa_t value);

      Style& backgroundImageTiled(bool value);

      Style& borderColor(lv_color_t value);

      Style& borderOpacity(lv_opa_t value);

      Style& borderWidth(int32_t value);

      Style& borderSide(lv_border_side_t value);

      Style& borderPost(bool value);

      Style& outlineWidth(int32_t value);

      Style& outlineColor(lv_color_t value);

      Style& outlineOpacity(lv_opa_t value);

      Style& outlinePad(int32_t value);

      Style& shadowWidth(int32_t value);

      Style& shadowOffsetX(int32_t value);

      Style& shadowOffsetY(int32_t value);

      Style& shadowSpread(int32_t value);

      Style& shadowColor(lv_color_t value);

      Style& shadowOpacity(lv_opa_t value);

      Style& imageOpacity(lv_opa_t value);

      Style& imageRecolor(lv_color_t value);

      Style& imageRecolorOpacity(lv_opa_t value);

      Style& lineWidth(int32_t value);

      Style& lineDashWidth(int32_t value);

      Style& lineDashGap(int32_t value);

      Style& lineRounded(bool value);

      Style& lineColor(lv_color_t value);

      Style& lineOpacity(lv_opa_t value);

      Style& arcWidth(int32_t value);

      Style& arcRounded(bool value);

      Style& arcColor(lv_color_t value);

      Style& arcOpacity(lv_opa_t value);

      Style& arcImageSrc(const void *value);

      Style& textColor(lv_color_t value);

      Style& textOpacity(lv_opa_t value);

      Style& textFont(const lv_font_t *value);

      Style& textLetterSpace(int32_t value);

      Style& textLineSpace(int32_t value);

      Style& textDecor(lv_text_decor_t value);

      Style& textAlign(lv_text_align_t value);

      Style& textOutlineStrokeColor(lv_color_t value);

      Style& textOutlineStrokeWidth(int32_t value);

      Style& textOutlineStrokeOpacity(lv_opa_t value);

      Style& radius(int32_t value);

      Style& radialOffset(int32_t value);

      Style& clipCorner(bool value);

      Style& opacity(lv_opa_t value);

      Style& opacityLayered(lv_opa_t value);

      Style& colorFilterDsc(const lv_color_filter_dsc_t *value);

      Style& colorFilterOpacity(lv_opa_t value);

      Style& recolor(lv_color_t value);

      Style& recolorOpacity(lv_opa_t value);

      Style& anim(const lv_anim_t *value);

      Style& animDuration(uint32_t value);

      Style& transition(const lv_style_transition_dsc_t *value);

      Style& blendMode(lv_blend_mode_t value);

      Style& layout(uint16_t value);

      Style& baseDir(lv_base_dir_t value);

      Style& bitmapMaskSrc(const void *value);

      Style& rotarySensitivity(uint32_t value);
    private:
      lv_style_t style;
  };
}