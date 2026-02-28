#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>

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

    app.tick();

    usleep(5);
  }

  app.stop();


  // iamaprogrammer::PortAudioBackend audioBackend;
  // audioBackend.initialize();

  // // Create audio reader
  // iamaprogrammer::SndlibAudioReader reader(1024);
  // reader.open(std::filesystem::path("/usr/bin") / "audio_library" / "01 Bay.wav");
  // iamaprogrammer::SRAudioResampler resampler(&reader, audioBackend.getDefaultAudioDevice().samplerate);

  // // Create audio stream
  // iamaprogrammer::PortAudioStream basicStream = iamaprogrammer::PortAudioStream(reader, resampler);
  // iamaprogrammer::AudioStream advancedStream = iamaprogrammer::AudioStream(&reader, &resampler, &basicStream);

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