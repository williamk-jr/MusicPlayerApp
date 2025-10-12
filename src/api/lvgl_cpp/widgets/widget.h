#pragma once

#include "../style/style.h"

extern "C" {
  #include "lvgl/lvgl.h"
}

namespace iamaprogrammer {
  class Widget {
    public:

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


    protected:
      virtual void create(lv_obj_t* parent);
      virtual void assign(lv_obj_t* object) final;

    private:
      lv_obj_t* widget = nullptr;
  };
}