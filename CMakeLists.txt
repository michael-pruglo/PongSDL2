cmake_minimum_required(VERSION 3.16)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pong src/main.cpp src/utility/Logger.hpp src/model/Pong.cpp src/model/Pong.hpp src/view/IRenderable.hpp src/view/Sprite.cpp src/view/Sprite.hpp src/model/Player.cpp src/model/Player.hpp src/model/Ball.cpp src/model/Ball.hpp src/view/GameWindow.cpp src/view/GameWindow.hpp src/utility/Rectangle.cpp src/utility/Rectangle.hpp src/view/Input.hpp src/controller/IInputManager.hpp src/controller/GameManager.cpp src/controller/GameManager.hpp src/controller/IGame.hpp)


set(SDL2_DIR C:/mingw64/x86_64-w64-mingw32)
set(SDL2_LIB_DIR ${SDL2_DIR}/lib)

include_directories(${SDL2_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/libSDL2.dll.a ${SDL2_LIB_DIR}/libSDL2main.a)
add_definitions(-DSDL_MAIN_HANDLED)