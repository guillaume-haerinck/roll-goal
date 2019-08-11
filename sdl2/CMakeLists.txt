# /////////////////////////////////////////////////////////////////////////////
# ///////////////////////////////// SETTINGS //////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

# Set standards
cmake_minimum_required(VERSION 3.10)
project(roll-goal C CXX)
set(CMAKE_CXX_STANDARD 17)
set(default_build_type "Release")

# Setup Conan
if (EMSCRIPTEN)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_WEBGL2=1 -std=c++17")
else()
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake")
    file(DOWNLOAD
        "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.14/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake")
    endif()
    include(${CMAKE_BINARY_DIR}/conan.cmake)
    conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP BUILD missing)
endif()

# /////////////////////////////////////////////////////////////////////////////
# ////////////////////////////// PROJECT FILES ////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

file(GLOB_RECURSE MY_SOURCES src/*)

# /////////////////////////////////////////////////////////////////////////////
# /////////////////////////////// DEPENDENCIES ////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

find_package(OpenGL REQUIRED)
if (WIN32)
    set(
        ULTRALIGHT_LIBRARIES 
        ${CMAKE_SOURCE_DIR}/lib/ultralight-1.0/lib/win/x64/Ultralight.lib;
        ${CMAKE_SOURCE_DIR}/lib/ultralight-1.0/lib/win/x64/UltralightCore.lib;
        ${CMAKE_SOURCE_DIR}/lib/ultralight-1.0/lib/win/x64/WebCore.lib;
    )
else()
    if (UNIX)
        set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/lib/ultralight-1.0/bin/linux)
    elseif (APPLE)
        set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/lib/ultralight-1.0/bin/mac)
    endif()

    find_library(ULTRALIGHT_LIB Ultralight)
    find_library(ULTRALIGHT_CORE_LIB UltralightCore)
    find_library(WEB_CORE_LIB WebCore)
    set(ULTRALIGHT_LIBRARIES ${ULTRALIGHT_LIB} ${ULTRALIGHT_CORE_LIB} ${WEB_CORE_LIB})
endif()

# ------------------------- BUILD DEPENDENCIES IF NEEDED ----------------------

add_library(GLAD STATIC "lib/glad/src/glad.c")
add_library(STB_IMAGE STATIC "lib/stb_image/stb_image.cpp")
add_library(IMGUI STATIC "lib/imgui/imgui_impl_opengl3.cpp" "lib/imgui/imgui_impl_sdl.cpp")

# /////////////////////////////////////////////////////////////////////////////
# ///////////////////////////////// INCLUDES //////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

include_directories(
    ${OPENGL_INCLUDE_DIR}
    lib/ultralight-1.0/include
    lib/glad/include
    lib
    src
    res
)

# /////////////////////////////////////////////////////////////////////////////
# /////////////////////////////////// BUILD ///////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${MY_SOURCES})
target_link_libraries(
    ${PROJECT_NAME}
    ${CONAN_LIBS}
    ${OPENGL_LIBRARIES}
    ${ULTRALIGHT_LIBRARIES}
    GLAD
    STB_IMAGE
    IMGUI
)

if (NOT WIN32)
    target_link_libraries(${PROJECT_NAME} -ldl)
endif()

# /////////////////////////////////////////////////////////////////////////////
# ///////////////////////////////// TESTING ///////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

if (NOT EMSCRIPTEN)
    list(REMOVE_ITEM MY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
    file(GLOB_RECURSE MY_TESTS test/*)
    add_executable(TEST_ROLL_GOAL ${MY_SOURCES} ${MY_TESTS})
    target_link_libraries(
        TEST_ROLL_GOAL
        ${CONAN_LIBS}
        ${OPENGL_LIBRARIES}
        ${ULTRALIGHT_LIBRARIES}
        GLAD
        STB_IMAGE
        IMGUI
    )
    if (UNIX) # Use dynamic linking library
        target_link_libraries(${PROJECT_NAME} -ldl)
    endif()

    # Make the test discoverable by CTest
    find_package(Catch2)
    if (Catch2)
        enable_testing()
        include(CTest)
        include(Catch)
        catch_discover_tests(TEST_ROLL_GOAL)
    endif()
endif()

# /////////////////////////////////////////////////////////////////////////////
# //////////////////////////////// POST-BUILD /////////////////////////////////
# /////////////////////////////////////////////////////////////////////////////

if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/lib/ultralight-1.0/bin/win/x64" $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
