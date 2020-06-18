cmake_minimum_required(VERSION 3.16)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pong src/main.cpp src/utility/Logger.hpp src/model/Pong.cpp src/model/Pong.hpp src/controller/IRenderable.hpp src/model/PongPlayer.hpp src/model/Ball.hpp src/view/GameWindow.cpp src/view/GameWindow.hpp src/utility/Rectangle.cpp src/utility/Rectangle.hpp src/controller/IInputManager.hpp src/controller/GameManager.cpp src/controller/GameManager.hpp src/controller/IGame.hpp src/utility/Random.cpp src/utility/Random.hpp src/view/TextSprite.cpp src/view/TextSprite.hpp src/controller/ISprite.hpp src/view/RectSprite.cpp src/view/RectSprite.hpp src/model/PongBot.cpp src/model/PongBot.hpp src/utility/MovementVector.hpp src/model/Ball.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

INCLUDE(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
#pkg_check_modules(SDL2_IMG REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
#pkg_check_modules(SDL2_MIX REQUIRED SDL2_mixer)

include_directories(
        ${SDL2_INCLUDE_DIRS}
#        ${SDL2_IMG_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
#        ${SDL2_MIX_INCLUDE_DIRS}
)

link_directories(
        ${SDL2_LIBRARY_DIRS}
#        ${SDL2_IMG_LIBRARY_DIRS}
        ${SDL2_TTF_LIBRARY_DIRS}
#        ${SDL2_MIX_LIBRARY_DIRS}
)

target_link_libraries(Pong
        ${SDL2_LIBRARIES}
#        ${SDL2_IMG_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
#        ${SDL2_MIX_LIBRARIES}
)


#set(SDL2_LIB_DIR ${PROJECT_SOURCE_DIR}/SDLFiles/lib)
#set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/SDLFiles/include)
#include_directories(${SDL2_INCLUDE_DIR})
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/libSDL2.dll.a ${SDL2_LIB_DIR}/libSDL2main.a )
add_definitions(-DSDL_MAIN_HANDLED)