cmake_minimum_required (VERSION 3.10)
project("musicapp")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/bin")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(libs/lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)

add_subdirectory("src")
target_include_directories(lvgl_cpp PUBLIC ${PROJECT_SOURCE_DIR}/src/api/lvgl_cpp)

# Create executable
add_executable(${PROJECT_NAME} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} lvgl lvgl::demos lvgl::thorvg m pthread lvgl_cpp libaudio)

\\wsl.localhost\Ubuntu\home\willk\MusicPlayer\aarch64-buildroot-linux-gnu_sdk-buildroot\aarch64-buildroot-linux-gnu
