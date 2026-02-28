#include "audio_control.h"

namespace iamaprogrammer {
  AudioControlWidget::AudioControlWidget(LvObject& parent) : LvObject(lv_obj_create(parent.getHandle())) {
    this->grid_columns = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    this->grid_rows = {LV_GRID_FR(3), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    this->grid = Grid(*this, this->grid_columns, this->grid_rows);
    this->grid.setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
    this->grid.setStyleBgColor(lv_palette_main(LV_PALETTE_RED), 0);
    this->grid.setSize(lv_pct(100), lv_pct(100));
    this->grid.center();
    this->grid.updateLayout();

    // Icon Cell
    this->iconCell = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 0, 1,
      LV_GRID_ALIGN_STRETCH, 0, 1
    );
    this->iconCell.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->iconCell.updateLayout();

    // Information Cell
    this->informationCell = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 0, 1,
      LV_GRID_ALIGN_STRETCH, 1, 1
    );
    this->informationCell.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->informationCell.updateLayout();

    // Control Cell
    this->controlCell = GridCell(this->grid,
      LV_GRID_ALIGN_STRETCH, 0, 1,
      LV_GRID_ALIGN_STRETCH, 2, 1
    );
    this->controlCell.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);
    this->controlCell.updateLayout();

    this->playPosition = SliderWidget(&informationCell);
    this->playPosition.setSize(lv_pct(100), lv_pct(33));
    this->playPosition.center();

    this->playButton = ButtonWidget(&controlCell);
    this->playButton.setSize(lv_pct(33), lv_pct(33));
    this->playButton.setStyleBgColor(lv_palette_main(LV_PALETTE_RED), 0);
    this->playButton.center();
  }

  void AudioControlWidget::start() {

  }

  void AudioControlWidget::stop() {

  }

  void AudioControlWidget::updateTrack(int position) {
    this->playPosition.setValue(position, 0);
  }

  void AudioControlWidget::setTrackDuration(int duration) {
    this->playPosition.setRange(0, duration);
  }

  int AudioControlWidget::getTrackDuration() {
    return this->playPosition.getValue();
  }
}