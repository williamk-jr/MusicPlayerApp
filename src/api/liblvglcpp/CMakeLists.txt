add_library(liblvglcpp STATIC 
  liblvglcpp/lvgl_cpp.cpp

  liblvglcpp/style/style.cpp
  
  liblvglcpp/widgets/lv_object.cpp
  liblvglcpp/widgets/button.cpp
  liblvglcpp/widgets/label.cpp
  liblvglcpp/widgets/slider.cpp
  liblvglcpp/widgets/list.cpp
  liblvglcpp/widgets/arc.cpp
  liblvglcpp/widgets/animimage.cpp
  liblvglcpp/widgets/bar.cpp
  liblvglcpp/widgets/checkbox.cpp
  liblvglcpp/widgets/dropdown.cpp
  liblvglcpp/widgets/image.cpp
  liblvglcpp/widgets/msgbox.cpp
  liblvglcpp/widgets/roller.cpp
  liblvglcpp/widgets/spinner.cpp
  liblvglcpp/widgets/switch.cpp
  liblvglcpp/widgets/btnmatrix.cpp
  liblvglcpp/widgets/calendar.cpp
  liblvglcpp/widgets/canvas.cpp
  liblvglcpp/widgets/chart.cpp
  liblvglcpp/widgets/imagebutton.cpp
  liblvglcpp/widgets/keyboard.cpp
  liblvglcpp/widgets/led.cpp
  liblvglcpp/widgets/line.cpp
  liblvglcpp/widgets/lottie.cpp
  liblvglcpp/widgets/menu.cpp
  liblvglcpp/widgets/scale.cpp
  liblvglcpp/widgets/spinbox.cpp
  liblvglcpp/widgets/table.cpp
  liblvglcpp/widgets/tabview.cpp
  liblvglcpp/widgets/textarea.cpp
  liblvglcpp/widgets/tileview.cpp
  liblvglcpp/widgets/win.cpp
  liblvglcpp/widgets/3dtexture.cpp

  liblvglcpp/widgets/layout/grid.cpp
  liblvglcpp/widgets/layout/grid_cell.cpp
)
target_include_directories(liblvglcpp PUBLIC ${CMAKE_SOURCE_DIR}/src/api/liblvglcpp)

target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)
target_link_libraries(liblvglcpp lvgl lvgl::demos lvgl::thorvg m pthread)