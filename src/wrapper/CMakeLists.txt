add_library(lvgl_wrapper STATIC 
  style/style.cpp
  widgets/widget.cpp
  widgets/button.cpp
  widgets/label.cpp
)
target_include_directories(lvgl_wrapper PUBLIC ${CMAKE_SOURCE_DIR}/src/wrapper)

target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)
target_link_libraries(lvgl_wrapper lvgl lvgl::demos lvgl::thorvg m pthread)