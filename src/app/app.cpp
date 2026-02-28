#include "app.h"

namespace iamaprogrammer {

  App::App() : mainpage(this->applicationModel) {
    
  }

  void App::start() {

    //iamaprogrammer::LvglCpp::create();
    lv_init();
    //this->startServices();

    // Init Display
    this->createDisplay();

    // Init Touchscreen
    this->createTouchDevice();

    // Init Gui
    this->createGui();

    // std::shared_ptr<OperationListMessage<nullptr_t, std::string>> message = 
    //     std::make_shared<OperationListMessage<nullptr_t, std::string>>();

    // for (std::string tableName : this->playlistRegistry.getTableNames()) {
    //   message->addOperation(MessageOperation::ADD, tableName);
    // }

    // this->eventBus.publish<OperationListMessage<nullptr_t, std::string>>(iamaprogrammer::EVENT_PLAYLIST_UPDATE, message);
  }

  void App::tick() {
    //this->eventBus.queryEvent();
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
    this->mainpage.init(this->display);
    std::cout << "something2" << std::endl;
  }
}