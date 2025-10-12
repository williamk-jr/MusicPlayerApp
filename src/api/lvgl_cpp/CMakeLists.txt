add_library(lvgl_cpp STATIC 
  style/style.cpp
  widgets/widget.cpp
  widgets/button.cpp
  widgets/label.cpp
  widgets/slider.cpp

  widgets/layout/grid.cpp
  widgets/layout/grid_cell.cpp
)
target_include_directories(lvgl_cpp PUBLIC ${CMAKE_SOURCE_DIR}/src/api/lvgl_cpp)

target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)
target_link_libraries(lvgl_cpp lvgl lvgl::demos lvgl::thorvg m pthread)