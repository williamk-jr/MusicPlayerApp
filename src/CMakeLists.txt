#add_subdirectory("api/audio")
add_subdirectory("api")

add_executable(${PROJECT_NAME} main.cpp
  app/gui/main_page.cpp

  app/services/service.cpp
  app/services/file_watcher_service.cpp
  app/app.cpp

)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/app)
target_link_libraries(${PROJECT_NAME} lvgl lvgl::demos lvgl::thorvg m pthread liblvglcpp libaudio)
