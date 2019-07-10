cmake_minimum_required(VERSION 2.8)
project(roll-goal-wasm)

include(conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE MY_SOURCES src/*)
add_executable(${PROJECT_NAME} ${MY_SOURCES})

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_WEBGL2=1")

target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES
  SUFFIX ".html"
  LINK_FLAGS "--emrun")

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
  
install(FILES
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.js
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.wasm
  DESTINATION bin)