cmake_minimum_required(VERSION 3.20)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES Sources/main.cpp Headers/State.h Sources/StateMachine.cpp Headers/StateMachine.h Sources/AssetManager.cpp Headers/AssetManager.h)
add_executable(HelloSFML ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)