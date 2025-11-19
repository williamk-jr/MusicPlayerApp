#include "app.h"

namespace iamaprogrammer {

  void App::start() {
    iamaprogrammer::LvglCpp::create();
    //this->startServices();

    // Init Display
    this->createDisplay();

    // Init Touchscreen
    this->createTouchDevice();

    // Init Gui
    this->createGui();
  }

  void App::stop() {
    this->stopServices();
  }

  void App::startServices() {
    //this->fileWatcherService.start(200);
  }

  void App::stopServices() {
    //this->fileWatcherService.stop();
  }

  void App::createDisplay() {
    this->display = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(this->display, "/dev/fb0");
    lv_display_set_rotation(this->display, LV_DISPLAY_ROTATION_90);
  }

  void App::createTouchDevice() {
    this->inputDevice = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event3");
    lv_indev_set_display(this->inputDevice, this->display);
  }

  void App::createGui() {
    mainpage.init(this->display);
  }
}