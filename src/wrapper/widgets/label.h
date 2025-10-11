#pragma once

#include "widget.h"

namespace iamaprogrammer {
  class LabelWidget: public Widget {
    public:
      LabelWidget(Widget* parent);


      LabelWidget(lv_obj_t* parent);


      void setText(const char *text);


      void setTextFmt(const char *fmt, ...);


      //void setTextVfmt(const char *fmt, va_list args);


      void setTextStatic(const char *text);


      void setLongMode(lv_label_long_mode_t long_mode);


      void setTextSelectionStart(uint32_t index);


      void setTextSelectionEnd(uint32_t index);


      void setRecolor(bool en);


      //void setTranslationTag(const char *tag);


      char* getText();


      lv_label_long_mode_t getLongMode();


      void getLetterPos(uint32_t char_id, lv_point_t *pos);


      uint32_t getLetterOn(lv_point_t *pos_in, bool bidi);


      bool isCharUnderPos(lv_point_t *pos);


      uint32_t getTextSelectionStart();


      uint32_t getTextSelectionEnd();


      bool getRecolor();


      lv_observer_t* bindText(lv_subject_t *subject, const char *fmt);


      void insText(uint32_t pos, const char *txt);


      void cutText(uint32_t pos, uint32_t cnt);

    protected:
      void create(lv_obj_t* parent) override;
  };
}