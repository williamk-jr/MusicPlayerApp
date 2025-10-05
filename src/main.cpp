#include <iostream>
#include <unistd.h>

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
  #include <style/style.h>
  #include <widgets/button.h>
  #include <widgets/label.h>
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

  iamaprogrammer::Style style = iamaprogrammer::Style()
    .backgroundColor(lv_palette_main(LV_PALETTE_GREEN))
    .radius(32);

  iamaprogrammer::ButtonWidget btn = iamaprogrammer::ButtonWidget(lv_screen_active());
  btn.addStyle(&style, 0);
  btn.setSize(100, 50);
  btn.center();

  iamaprogrammer::LabelWidget label = iamaprogrammer::LabelWidget(&btn);
  label.setText("Hello World!");
  label.center();

  
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