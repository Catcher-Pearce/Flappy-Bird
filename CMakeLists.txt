cmake_minimum_required(VERSION 3.16)
project(FlappyBird LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically download and build raylib
include(FetchContent)
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# Define your executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Window.cpp
        src/Window.h
        src/Player.cpp
        src/Player.h
        src/Pipe.cpp
        src/Pipe.h)

# Link raylib to your project
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
