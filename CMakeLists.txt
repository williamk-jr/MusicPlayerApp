cmake_minimum_required (VERSION 3.10)
project("$ENV{EXECUTABLE_NAME}")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/$ENV{EXECUTABLE_PATH}")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

add_subdirectory(libs/lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR}/libs)

add_subdirectory("src")
target_include_directories(lvgl_wrapper PUBLIC ${PROJECT_SOURCE_DIR}/src/wrapper)

# Create executable
add_executable(${PROJECT_NAME} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} lvgl lvgl::demos lvgl::thorvg m pthread lvgl_wrapper)

