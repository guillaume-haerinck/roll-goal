# NOT WORKING YET
# em++ src/main.cpp -s USE_SDL=2 -s USE_WEBGL2=1 -o dist/index.html
# emrun --port 8080 dist/index.html

# Requirement
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_C_COMPILER emcc)
set(CMAKE_CPP_COMPILER em++)

# ---------------------------------------- PROJECT FILES
project(roll-goal)
file(GLOB_RECURSE MY_SOURCES src/*)

# ----------------------------------------- INCLUDE DIRECTORIES
include_directories(
    lib
    src
)

# ------------------------------------------- BUILD PROJECT
# set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${MY_SOURCES})

