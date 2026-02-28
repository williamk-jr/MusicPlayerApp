#add_subdirectory("api/audio")
add_subdirectory("api")

add_executable(${PROJECT_NAME} main.cpp
  app/crypt/md5.cpp

  app/gui/widgets/audio_control.cpp
  app/gui/pages/page.cpp
  app/gui/pages/main_page.cpp
  app/gui/util/grid.cpp
  app/gui/util/style.cpp
  app/gui/util/util.cpp

  app/event/event_bus.cpp
  app/event/observable/observable.h

  app/state/application_model.cpp

  app/services/service.cpp
  app/services/file_watcher_service.cpp
  app/app_events.cpp
  app/app.cpp
)

find_package(Sqlite3)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/app)
target_link_libraries(${PROJECT_NAME} lvgl lvgl::demos lvgl::thorvg m pthread libaudio registry liblvglcpp)
