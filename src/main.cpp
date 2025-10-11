#include <iostream>
#include <string>
#include <unistd.h>

#include <style/style.h>
#include <widgets/button.h>
#include <widgets/label.h>
#include <widgets/slider.h>
#include <widgets/layout/grid.h>
#include <widgets/layout/grid_cell.h>

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

void btn_event(lv_event_t* e);

int main() {
  std::cout << "Hello World" << std::endl;

  lv_init();

  lv_display_t *disp = lv_linux_fbdev_create();
  lv_linux_fbdev_set_file(disp, "/dev/fb0");

  // Input device.
  lv_indev_t* indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
  lv_evdev_set_calibration(indev, 0, 0, 1024, 600);
  lv_indev_set_display(indev, disp);

  iamaprogrammer::Grid grid(lv_screen_active(), {300, 300, 300, LV_GRID_TEMPLATE_LAST}, {300, 300, 300, LV_GRID_TEMPLATE_LAST});
  grid.setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
  grid.setSize(900, 900);
  grid.center();

  iamaprogrammer::Style cellStyle = iamaprogrammer::Style()
    .backgroundColor(lv_palette_main(LV_PALETTE_GREY));

  std::vector<iamaprogrammer::GridCell> gridCells;
  std::vector<iamaprogrammer::LabelWidget> gridLabels;

  for (int i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;

    gridCells.push_back(iamaprogrammer::GridCell(&grid, LV_GRID_ALIGN_STRETCH, col, LV_GRID_ALIGN_STRETCH, row));
    gridCells[i].addStyle(&cellStyle, 0);

    gridLabels.push_back(iamaprogrammer::LabelWidget(&gridCells[i]));
    gridLabels[i].setText("hi");
    gridLabels[i].center();
  }




  // iamaprogrammer::Style style = iamaprogrammer::Style()
  //   .backgroundColor(lv_palette_main(LV_PALETTE_GREEN))
  //   .radius(32);

  // iamaprogrammer::ButtonWidget btn = iamaprogrammer::ButtonWidget(lv_screen_active());
  // btn.addStyle(&style, 0);
  // btn.setSize(100, 50);
  // btn.center();
  

  // iamaprogrammer::LabelWidget label = iamaprogrammer::LabelWidget(&btn);
  // label.setText("Hello World!");
  // label.center();

  // iamaprogrammer::SliderWidget slider = iamaprogrammer::SliderWidget(lv_screen_active());
  // slider.setRange(0, 100);
  // slider.setValue(50, LV_ANIM_OFF);
  // slider.center();

  // iamaprogrammer::LabelWidget label2 = iamaprogrammer::LabelWidget(&slider);
  // label2.setText("50%");
  // label2.center();

  
  while (1) {
    lv_timer_handler();
    usleep(5);
  }
  return 0;
}

void btn_event(lv_event_t* e) {
  lv_obj_t* btn = lv_event_get_target_obj(e);
  lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_RED), 0);
  //std::cout << "Clicked" << std::endl;
}