cmake_minimum_required(VERSION 3.20)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES Sources/main.cpp Headers/State.h Sources/StateMachine.cpp Headers/StateMachine.h
        Sources/AssetManager.cpp Headers/AssetManager.h Sources/InputManager.cpp Headers/InputManager.h
        Sources/Game.cpp Headers/Game.h Resources Headers/DEFINITIONS.h Sources/SplashState.cpp
        Headers/SplashState.h Sources/MainMenuState.cpp Headers/MainMenuState.h Sources/GameState.cpp Headers/GameState.h Sources/GameOverState.cpp Headers/GameOverState.h Sources/Pipe.cpp Headers/Pipe.h Sources/Land.cpp Headers/Land.h Sources/Bird.cpp Headers/Bird.h Sources/Collision.cpp Headers/Collision.h Sources/Flash.cpp Headers/Flash.h)
add_executable(HelloSFML ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)