add_library(liblvglcpp STATIC 
  liblvglcpp/lvgl_cpp.cpp

  liblvglcpp/events/event_bus.cpp

  liblvglcpp/style/style.cpp
  liblvglcpp/widgets/widget.cpp
  liblvglcpp/widgets/button.cpp
  liblvglcpp/widgets/label.cpp
  liblvglcpp/widgets/slider.cpp

  liblvglcpp/widgets/layout/grid.cpp
  liblvglcpp/widgets/layout/grid_cell.cpp
)
target_include_directories(liblvglcpp PUBLIC ${CMAKE_SOURCE_DIR}/src/api/liblvglcpp)

target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)
target_link_libraries(liblvglcpp lvgl lvgl::demos lvgl::thorvg m pthread)