#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>

#include <liblvglcpp/lvgl_cpp.h>

#include <libaudio/backends/port_audio_backend.h>
#include <libaudio/reader/sndlib_audio_reader.h>
#include <libaudio/resampler/sr_audio_resampler.h>
#include <libaudio/audio_stream.h>

#include "app/app.h"

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

void btn_event(lv_event_t* e);


// musicapp >> log.txt 2>&1
// less log.txt
int main() {
  iamaprogrammer::App app;
  app.start();

  while (1) {
    lv_timer_handler();
    usleep(5);
  }

  app.stop();
  // std::filesystem::path DATA("/etc/musicapp");
  // std::filesystem::path AUDIO_LIBRARY = DATA / "library";
  // std::filesystem::path PLAYLISTS = DATA / "playlists";

  // //Init LVGL graphics library.
  // iamaprogrammer::LvglCpp::create();
  // iamaprogrammer::EventBus eventBus;

  // iamaprogrammer::FileWatcherService fileWatcherService(&eventBus, DATA);
  // fileWatcherService.start(200);

  // // Init Display
  // lv_display_t *disp = lv_linux_fbdev_create();
  // lv_linux_fbdev_set_file(disp, "/dev/fb0");
  // lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);

  // // Init Touchscreen
  // lv_indev_t* indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event3");
  // lv_indev_set_display(indev, disp);

  // int32_t screen_width = lv_display_get_horizontal_resolution(disp);
  // int32_t screen_height = lv_display_get_vertical_resolution(disp);

  // int32_t row1_height = screen_height / 7.5;
  // int32_t row2_height = screen_height - row1_height;

  // // Main Grid
  // iamaprogrammer::Grid grid(
  //   lv_screen_active(), 
  //   {screen_width/3, screen_width/3, screen_width/3, LV_GRID_TEMPLATE_LAST}, 
  //   {row1_height, row2_height, LV_GRID_TEMPLATE_LAST}
  // );
  // grid.setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
  // grid.setStyleBgColor(lv_palette_main(LV_PALETTE_RED), 0);
  // grid.setSize(screen_width, screen_height);
  // grid.center();

  // iamaprogrammer::Style cellStyle = iamaprogrammer::Style()
  //   .backgroundColor(lv_palette_main(LV_PALETTE_GREY));

  // iamaprogrammer::GridCell navBar(&grid, 
  //   LV_GRID_ALIGN_STRETCH, 0, 3, 
  //   LV_GRID_ALIGN_STRETCH, 0, 1
  // );
  // navBar.setStyleBgColor(lv_palette_main(LV_PALETTE_GREY), 0);

  // iamaprogrammer::GridCell playlists(&grid, 
  //   LV_GRID_ALIGN_STRETCH, 0, 1, 
  //   LV_GRID_ALIGN_STRETCH, 1, 1
  // );
  // playlists.setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 1), 0);

  // iamaprogrammer::GridCell songs(&grid, 
  //   LV_GRID_ALIGN_STRETCH, 1, 1, 
  //   LV_GRID_ALIGN_STRETCH, 1, 1
  // );
  // songs.setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 2), 0);

  // iamaprogrammer::GridCell song(&grid, 
  //   LV_GRID_ALIGN_STRETCH, 2, 1, 
  //   LV_GRID_ALIGN_STRETCH, 1, 1
  // );
  // song.setStyleBgColor(lv_palette_lighten(LV_PALETTE_GREY, 3), 0);

  // std::vector<iamaprogrammer::GridCell> gridCells;
  // std::vector<iamaprogrammer::ButtonWidget> gridButtons;
  // std::vector<iamaprogrammer::LabelWidget> gridLabels;

  // for (int i = 0; i < 9; i++) {
  //   int row = i / 3;
  //   int col = i % 3;

  //   gridCells.push_back(iamaprogrammer::GridCell(&grid, LV_GRID_ALIGN_STRETCH, col, LV_GRID_ALIGN_STRETCH, row));
  //   gridCells[i].addStyle(&cellStyle, 0);

  //   gridButtons.push_back(iamaprogrammer::ButtonWidget(&gridCells[i]));
  //   gridButtons[i].addEventCallback(btn_event, LV_EVENT_CLICKED, nullptr);
  //   gridButtons[i].center();

  //   gridLabels.push_back(iamaprogrammer::LabelWidget(&gridButtons[i]));
  //   gridLabels[i].setText("hi");
  //   gridLabels[i].center();
  // }

  //Audio testing

  //Create audio reader


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

  return 0;
}

// Input device.
//lv_indev_t* indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event1");
//lv_evdev_set_calibration(indev, 0, 0, 1024, 600);
//lv_indev_set_display(indev, disp);

void btn_event(lv_event_t* e) {
  lv_obj_t* btn = lv_event_get_target_obj(e);
  lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_RED), 0);
  //std::cout << "Clicked" << std::endl;
}

/*

iamaprogrammer::PortAudioBackend audioBackend;
audioBackend.initialize();

// Create audio reader
iamaprogrammer::SndlibAudioReader reader(1024);
reader.open(std::filesystem::path("/usr/bin") / "audio_library" / "01 Bay.wav");
iamaprogrammer::SRAudioResampler resampler(&reader, audioBackend.getDefaultAudioDevice().samplerate);

// Create intermediate buffer
iamaprogrammer::AudioBuffer sharedAudioBuffer(
  reader.getAudioFileDescriptor(), 
  reader.getFrameReadCount() * resampler.getSampleRateConversionRatio()
);

// Create audio stream
iamaprogrammer::PortAudioStream basicStream = iamaprogrammer::PortAudioStream(&sharedAudioBuffer);
iamaprogrammer::AudioStream advancedStream = iamaprogrammer::AudioStream(&reader, &resampler, &basicStream);

advancedStream.setup();
advancedStream.start();

while (!advancedStream.isFinished()) {
  Pa_Sleep(1000);
  std::cout << advancedStream.position() << " s/ " << advancedStream.duration() << " s" << std::endl;
}
// Pa_Sleep(10000);
// advancedStream.seek(-3);
// Pa_Sleep(10000);
advancedStream.stop();
advancedStream.end();

reader.close();
resampler.close();
audioBackend.terminate();
*/