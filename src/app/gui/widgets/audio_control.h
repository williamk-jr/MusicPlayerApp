#pragma once
#include <liblvglcpp/lvgl_cpp.h>

namespace iamaprogrammer {
  // namespace AudioEvents {
  //   uint32_t AUDIO_PLAY_EVENT = lv_event_register_id();
  //   uint32_t AUDIO_STOP_EVENT = lv_event_register_id();
  //   uint32_t AUDIO_SEEK_EVENT = lv_event_register_id();
  //   uint32_t AUDIO_UPDATE_SEEKER_EVENT = lv_event_register_id();
  // }

  class AudioControlWidget: public LvObject {
    public:
      AudioControlWidget() = default;
      AudioControlWidget(LvObject& parent);

      void start();
      void stop();
      void updateTrack(int position);
      void setTrackDuration(int duration);
      int getTrackDuration();
      
    private:
      std::vector<int32_t> grid_columns;
      std::vector<int32_t> grid_rows;
      Grid grid;

      GridCell iconCell;
      GridCell informationCell;
      GridCell controlCell;

      ButtonWidget playButton;
      SliderWidget playPosition;

  };
}