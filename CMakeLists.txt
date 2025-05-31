cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(--coverage)
add_link_options(--coverage)

project(RK1)

add_subdirectory(third-party/gtest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_library(State STATIC src/WakeWordState.cpp src/FaceRecogntionState.cpp src/ObjectDetectionState.cpp src/SpeechRecognitionState.cpp src/Robot.cpp)
target_link_libraries(State Qt5::Core)

add_executable(main src/main.cpp)

target_link_libraries(main State Qt5::Core) 


add_subdirectory(tests)











