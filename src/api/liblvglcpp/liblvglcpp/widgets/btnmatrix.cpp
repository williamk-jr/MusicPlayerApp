#include "btnmatrix.h"

namespace iamaprogrammer {
  ButtonMatrixWidget::ButtonMatrixWidget(LvObject* parent) :
    LvObject(lv_btnmatrix_create(parent->getHandle())) {}

  void ButtonMatrixWidget::setMap(const std::vector<const char*>& map) {
    std::vector<const char*> m = map;
    m.push_back(nullptr);
    lv_btnmatrix_set_map(this->getHandle(), m.data());
  }

  void ButtonMatrixWidget::setSelected(int32_t id) {
    lv_btnmatrix_set_selected_btn(this->getHandle(), id);
  }

  int32_t ButtonMatrixWidget::getSelected() {
    return lv_btnmatrix_get_selected_btn(this->getHandle());
  }

  void ButtonMatrixWidget::setButtonCtrl(uint16_t btnId, lv_btnmatrix_ctrl_t ctrl) {
    lv_btnmatrix_set_btn_ctrl(this->getHandle(), btnId, ctrl);
  }

  void ButtonMatrixWidget::clearButtonCtrl(uint16_t btnId, lv_btnmatrix_ctrl_t ctrl) {
    lv_btnmatrix_clear_btn_ctrl(this->getHandle(), btnId, ctrl);
  }
}
