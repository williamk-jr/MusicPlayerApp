#include "label.h"

namespace iamaprogrammer {
  LabelWidget::LabelWidget(Widget* parent) {
    this->create(parent->getHandle());
  }


  LabelWidget::LabelWidget(lv_obj_t* parent) {
    this->create(parent);
  }
  
  
  void LabelWidget::create(lv_obj_t* parent) {
    this->assign(
      lv_label_create(parent)
    );
  }


  void LabelWidget::setText(const char *text) {
    lv_label_set_text(this->getHandle(), text);
  }


  void LabelWidget::setTextFmt(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    lv_label_set_text_fmt(this->getHandle(), fmt, args);
    va_end(args);
  }


  void LabelWidget::setTextStatic(const char *text) {
    lv_label_set_text_static(this->getHandle(), text);
  }


  void LabelWidget::setLongMode(lv_label_long_mode_t long_mode) {
  lv_label_set_long_mode(this->getHandle(), long_mode);
  }


  void LabelWidget::setTextSelectionStart(uint32_t index) {
    lv_label_set_text_selection_start(this->getHandle(), index);
  }


  void LabelWidget::setTextSelectionEnd(uint32_t index) {
    lv_label_set_text_selection_end(this->getHandle(), index);
  }


  void LabelWidget::setRecolor(bool en) {
    lv_label_set_recolor(this->getHandle(), en);
  }


  char* LabelWidget::getText() {
    return lv_label_get_text(this->getHandle());
  }


  lv_label_long_mode_t LabelWidget::getLongMode() {
    return lv_label_get_long_mode(this->getHandle());
  }


  void LabelWidget::getLetterPos(uint32_t char_id, lv_point_t *pos) {
    return lv_label_get_letter_pos(this->getHandle(), char_id, pos);
  }


  uint32_t LabelWidget::getLetterOn(lv_point_t *pos_in, bool bidi) {
    return lv_label_get_letter_on(this->getHandle(), pos_in, bidi);
  }


  bool LabelWidget::isCharUnderPos(lv_point_t *pos) {
    return lv_label_is_char_under_pos(this->getHandle(), pos);
  }


  uint32_t LabelWidget::getTextSelectionStart() {
    return lv_label_get_text_selection_start(this->getHandle());
  }


  uint32_t LabelWidget::getTextSelectionEnd() {
    return lv_label_get_text_selection_end(this->getHandle());
  }


  bool LabelWidget::getRecolor() {
    return lv_label_get_recolor(this->getHandle());
  }


  lv_observer_t* LabelWidget::bindText(lv_subject_t *subject, const char *fmt) {
    return lv_label_bind_text(this->getHandle(), subject, fmt);
  }


  void LabelWidget::insText(uint32_t pos, const char *txt) {
    lv_label_ins_text(this->getHandle(), pos, txt);
  }


  void LabelWidget::cutText(uint32_t pos, uint32_t cnt) {
    lv_label_cut_text(this->getHandle(), pos, cnt);
  }
}