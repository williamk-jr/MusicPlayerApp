#pragma once

#include "../style/style.h"

extern "C" {
  #include "lvgl/lvgl.h"
}

namespace iamaprogrammer {
  class Widget {
    public:

      ~Widget();


      virtual lv_obj_t* getHandle() final;


      void setPos(int32_t x, int32_t y);


      void setX(int32_t x);


      void setY(int32_t y);


      void setSize(int32_t w, int32_t h);


      bool refrSize();


      void setWidth(int32_t w);


      void setHeight(int32_t h);


      void setContentWidth(int32_t w);


      void setContentHeight(int32_t h);


      void setLayout(uint32_t layout);


      bool isLayoutPositioned();


      void markLayoutAsDirty();


      void updateLayout();


      void setAlign(lv_align_t align);


      void align(lv_align_t align, int32_t x_ofs, int32_t y_ofs);


      void alignTo(const lv_obj_t *base, lv_align_t align, int32_t x_ofs, int32_t y_ofs);


      void center();


      void setTransform(const lv_matrix_t *matrix);


      void resetTransform();


      void getCoords(lv_area_t *coords);


      int32_t getX();


      int32_t getX2();


      int32_t getY();


      int32_t getY2();


      int32_t getXAligned();


      int32_t getYAligned();


      int32_t getWidth();


      int32_t getHeight();


      int32_t getContentWidth();


      int32_t getContentHeight();


      void getContentCoords(lv_area_t *area);


      int32_t getSelfWidth();


      int32_t getSelfHeight();


      bool refreshSelfSize();


      void refrPos();


      void moveTo(int32_t x, int32_t y);


      void moveChildrenBy(int32_t x_diff, int32_t y_diff, bool ignore_floating);


      const lv_matrix_t *getTransform();


      void transformPoint(lv_point_t *p, lv_obj_point_transform_flag_t flags);


      void transformPointArray(lv_point_t points[], size_t count, lv_obj_point_transform_flag_t flags);


      void getTransformedArea(lv_area_t *area, lv_obj_point_transform_flag_t flags);


      void invalidateArea(const lv_area_t *area);


      void invalidate();


      bool areaIsVisible(lv_area_t *area);


      bool isVisible();


      void setExtClickArea(int32_t size);


      void getClickArea(lv_area_t *area);


      bool hitTest(const lv_point_t *point);


      void addStyle(Style* style, lv_style_selector_t selector);

      
      void addEventCallback(lv_event_cb_t event_cb, lv_event_code_t filter, void* user_data);
      void sendEvent(uint32_t event_code, void* param);
      
      void setStyleWidth(int32_t value, lv_style_selector_t selector);
      void setStyleMinWidth(int32_t value, lv_style_selector_t selector);
      void setStyleMaxWidth(int32_t value, lv_style_selector_t selector);
      void setStyleHeight(int32_t value, lv_style_selector_t selector);
      void setStyleMinHeight(int32_t value, lv_style_selector_t selector);
      void setStyleMaxHeight(int32_t value, lv_style_selector_t selector);
      void setStyleLength(int32_t value, lv_style_selector_t selector);
      void setStyleX(int32_t value, lv_style_selector_t selector);
      void setStyleY(int32_t value, lv_style_selector_t selector);
      void setStyleAlign(lv_align_t value, lv_style_selector_t selector);
      void setStyleTransformWidth(int32_t value, lv_style_selector_t selector);
      void setStyleTransformHeight(int32_t value, lv_style_selector_t selector);
      void setStyleTranslateX(int32_t value, lv_style_selector_t selector);
      void setStyleTranslateY(int32_t value, lv_style_selector_t selector);
      void setStyleTranslateRadial(int32_t value, lv_style_selector_t selector);
      void setStyleTransformScaleX(int32_t value, lv_style_selector_t selector);
      void setStyleTransformScaleY(int32_t value, lv_style_selector_t selector);
      void setStyleTransformRotation(int32_t value, lv_style_selector_t selector);
      void setStyleTransformPivotX(int32_t value, lv_style_selector_t selector);
      void setStyleTransformPivotY(int32_t value, lv_style_selector_t selector);
      void setStyleTransformSkewX(int32_t value, lv_style_selector_t selector);
      void setStyleTransformSkewY(int32_t value, lv_style_selector_t selector);
      void setStylePadTop(int32_t value, lv_style_selector_t selector);
      void setStylePadBottom(int32_t value, lv_style_selector_t selector);
      void setStylePadLeft(int32_t value, lv_style_selector_t selector);
      void setStylePadRight(int32_t value, lv_style_selector_t selector);
      void setStylePadRow(int32_t value, lv_style_selector_t selector);
      void setStylePadColumn(int32_t value, lv_style_selector_t selector);
      void setStylePadRadial(int32_t value, lv_style_selector_t selector);
      void setStyleMarginTop(int32_t value, lv_style_selector_t selector);
      void setStyleMarginBottom(int32_t value, lv_style_selector_t selector);
      void setStyleMarginLeft(int32_t value, lv_style_selector_t selector);
      void setStyleMarginRight(int32_t value, lv_style_selector_t selector);
      void setStyleBgColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleBgOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBgGradColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleBgGradDir(lv_grad_dir_t value, lv_style_selector_t selector);
      void setStyleBgMainStop(int32_t value, lv_style_selector_t selector);
      void setStyleBgGradStop(int32_t value, lv_style_selector_t selector);
      void setStyleBgMainOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBgGradOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBgGrad(const lv_grad_dsc_t * value, lv_style_selector_t selector);
      void setStyleBgImageSrc(const void * value, lv_style_selector_t selector);
      void setStyleBgImageOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBgImageRecolor(lv_color_t value, lv_style_selector_t selector);
      void setStyleBgImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBgImageTiled(bool value, lv_style_selector_t selector);
      void setStyleBorderColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleBorderOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleBorderWidth(int32_t value, lv_style_selector_t selector);
      void setStyleBorderSide(lv_border_side_t value, lv_style_selector_t selector);
      void setStyleBorderPost(bool value, lv_style_selector_t selector);
      void setStyleOutlineWidth(int32_t value, lv_style_selector_t selector);
      void setStyleOutlineColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleOutlineOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleOutlinePad(int32_t value, lv_style_selector_t selector);
      void setStyleShadowWidth(int32_t value, lv_style_selector_t selector);
      void setStyleShadowOffsetX(int32_t value, lv_style_selector_t selector);
      void setStyleShadowOffsetY(int32_t value, lv_style_selector_t selector);
      void setStyleShadowSpread(int32_t value, lv_style_selector_t selector);
      void setStyleShadowColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleShadowOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleImageOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleImageRecolor(lv_color_t value, lv_style_selector_t selector);
      void setStyleImageRecolorOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleLineWidth(int32_t value, lv_style_selector_t selector);
      void setStyleLineDashWidth(int32_t value, lv_style_selector_t selector);
      void setStyleLineDashGap(int32_t value, lv_style_selector_t selector);
      void setStyleLineRounded(bool value, lv_style_selector_t selector);
      void setStyleLineColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleLineOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleArcWidth(int32_t value, lv_style_selector_t selector);
      void setStyleArcRounded(bool value, lv_style_selector_t selector);
      void setStyleArcColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleArcOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleArcImageSrc(const void * value, lv_style_selector_t selector);
      void setStyleTextColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleTextOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleTextFont(const lv_font_t * value, lv_style_selector_t selector);
      void setStyleTextLetterSpace(int32_t value, lv_style_selector_t selector);
      void setStyleTextLineSpace(int32_t value, lv_style_selector_t selector);
      void setStyleTextDecor(lv_text_decor_t value, lv_style_selector_t selector);
      void setStyleTextAlign(lv_text_align_t value, lv_style_selector_t selector);
      void setStyleTextOutlineStrokeColor(lv_color_t value, lv_style_selector_t selector);
      void setStyleTextOutlineStrokeWidth(int32_t value, lv_style_selector_t selector);
      void setStyleTextOutlineStrokeOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleRadius(int32_t value, lv_style_selector_t selector);
      void setStyleRadialOffset(int32_t value, lv_style_selector_t selector);
      void setStyleClipCorner(bool value, lv_style_selector_t selector);
      void setStyleOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleOpaLayered(lv_opa_t value, lv_style_selector_t selector);
      void setStyleColorFilterDsc(const lv_color_filter_dsc_t * value, lv_style_selector_t selector);
      void setStyleColorFilterOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleRecolor(lv_color_t value, lv_style_selector_t selector);
      void setStyleRecolorOpa(lv_opa_t value, lv_style_selector_t selector);
      void setStyleAnim(const lv_anim_t * value, lv_style_selector_t selector);
      void setStyleAnimDuration(uint32_t value, lv_style_selector_t selector);
      void setStyleTransition(const lv_style_transition_dsc_t * value, lv_style_selector_t selector);
      void setStyleBlendMode(lv_blend_mode_t value, lv_style_selector_t selector);
      void setStyleLayout(uint16_t value, lv_style_selector_t selector);
      void setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector);
      void setStyleBitmapMaskSrc(const void * value, lv_style_selector_t selector);
      void setStyleRotarySensitivity(uint32_t value, lv_style_selector_t selector);

      void setStyleFlexFlow(lv_flex_flow_t value, lv_style_selector_t selector);
      void setStyleFlexMainPlace(lv_flex_align_t value, lv_style_selector_t selector);
      void setStyleFlexCrossPlace(lv_flex_align_t value, lv_style_selector_t selector);
      void setStyleFlexTrackPlace(lv_flex_align_t value, lv_style_selector_t selector);
      void setStyleFlexGrow(uint8_t value, lv_style_selector_t selector);

      void setStyleGridColumnDscArray(const int32_t * value, lv_style_selector_t selector);
      void setStyleGridColumnAlign(lv_grid_align_t value, lv_style_selector_t selector);
      void setStyleGridRowDscArray(const int32_t * value, lv_style_selector_t selector);
      void setStyleGridRowAlign(lv_grid_align_t value, lv_style_selector_t selector);
      void setStyleGridCellColumnPos(int32_t value, lv_style_selector_t selector);
      void setStyleGridCellXAlign(lv_grid_align_t value, lv_style_selector_t selector);
      void setStyleGridCellColumnSpan(int32_t value, lv_style_selector_t selector);
      void setStyleGridCellRowPos(int32_t value, lv_style_selector_t selector);
      void setStyleGridCellYAlign(lv_grid_align_t value, lv_style_selector_t selector);
      void setStyleGridCellRowSpan(int32_t value, lv_style_selector_t selector);


    protected:
      virtual void create(lv_obj_t* parent);
      virtual void assign(lv_obj_t* object) final;

    private:
      lv_obj_t* widget = nullptr;

  };
}