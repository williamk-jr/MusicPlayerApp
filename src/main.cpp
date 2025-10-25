#include <iostream>
#include <string>
#include <unistd.h>

#include <liblvglcpp/lvgl_cpp.h>

#include <libaudio/backends/port_audio_backend.h>
#include <libaudio/reader/sndlib_audio_reader.h>
#include <libaudio/resampler/sr_audio_resampler.h>
#include <libaudio/audio_stream.h>

extern "C" {
  #include "lvgl/lvgl.h"
  #include "lvgl/demos/lv_demos.h"
  #include "lvgl/src/drivers/evdev/lv_evdev.h"
}

void btn_event(lv_event_t* e);


// musicapp >> log.txt 2>&1
// less log.txt
int main() {;

  // Init LVGL graphics library.
  // iamaprogrammer::LvglCpp::create();

  // // Init audio backend
  iamaprogrammer::PortAudioBackend audioBackend;
  audioBackend.initialize();

  // lv_display_t *disp = lv_linux_fbdev_create();
  // lv_linux_fbdev_set_file(disp, "/dev/fb0");

  // iamaprogrammer::Grid grid(lv_screen_active(), {250, 250, 250, LV_GRID_TEMPLATE_LAST}, {250, 250, 250, LV_GRID_TEMPLATE_LAST});
  // grid.setGridAlign(LV_GRID_ALIGN_SPACE_BETWEEN, LV_GRID_ALIGN_SPACE_BETWEEN);
  // grid.setSize(900, 900);
  // grid.center();

  // iamaprogrammer::Style cellStyle = iamaprogrammer::Style()
  //   .backgroundColor(lv_palette_main(LV_PALETTE_GREY));

  // std::vector<iamaprogrammer::GridCell> gridCells;
  // std::vector<iamaprogrammer::LabelWidget> gridLabels;

  // for (int i = 0; i < 9; i++) {
  //   int row = i / 3;
  //   int col = i % 3;

  //   gridCells.push_back(iamaprogrammer::GridCell(&grid, LV_GRID_ALIGN_STRETCH, col, LV_GRID_ALIGN_STRETCH, row));
  //   gridCells[i].addStyle(&cellStyle, 0);

  //   gridLabels.push_back(iamaprogrammer::LabelWidget(&gridCells[i]));
  //   gridLabels[i].setText("hi");
  //   gridLabels[i].center();
  // }

  // Audio testing

  // Create audio reader
  iamaprogrammer::SndlibAudioReader reader(1024);
  reader.open(std::filesystem::path("/usr/bin") / "audio_library" / "01 Bay.wav");
  iamaprogrammer::SRAudioResampler resampler(&reader, audioBackend.getDefaultAudioDevice().samplerate);

  // Create intermediate buffer
  iamaprogrammer::AudioBuffer sharedAudioBuffer(
    reader.getAudioFileDescriptor(), 
    reader.getReadSize() * resampler.getSampleRateConversionRatio(),
    reader.getReadSize()
  );

  // Create audio stream
  iamaprogrammer::PortAudioStream basicStream = iamaprogrammer::PortAudioStream(&sharedAudioBuffer);
  iamaprogrammer::AudioStream advancedStream = iamaprogrammer::AudioStream(&reader, &resampler, &basicStream);

  advancedStream.setup();
  advancedStream.start();
  Pa_Sleep(10000);
  // advancedStream.seek(-3);
  // Pa_Sleep(10000);
  advancedStream.stop();
  advancedStream.end();


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

  
  // while (1) {
  //   lv_timer_handler();
  //   usleep(5);
  // }

  reader.close();
  resampler.close();
  audioBackend.terminate();
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