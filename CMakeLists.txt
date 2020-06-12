cmake_minimum_required(VERSION 3.16)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pong main.cpp)


set(SDL2_DIR C:/mingw64/x86_64-w64-mingw32)
set(SDL2_LIB_DIR ${SDL2_DIR}/lib)

include_directories(${SDL2_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/libSDL2.dll.a ${SDL2_LIB_DIR}/libSDL2main.a -mwindows)
add_definitions(-DSDL_MAIN_HANDLED)