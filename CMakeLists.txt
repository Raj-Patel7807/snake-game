cmake_minimum_required(VERSION 4.2)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES "src/*.cpp")

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

add_executable(SnakeGame ${SOURCES}
        src/powerups/PowerUp.cpp)

target_include_directories(SnakeGame PRIVATE src)

if (WIN32)
    target_link_options(SnakeGame PRIVATE -static -static-libgcc -static-libstdc++)
endif()
