cmake_minimum_required(VERSION 3.20)

project(TowerDefense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(TowerDefense
    src/Main.cpp
    src/Menu.cpp
)

# tells CMake to look in the 'src' folder for your .h files
target_include_directories(TowerDefense PRIVATE src)

target_link_libraries(TowerDefense
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

#  this copies your assets folder into the build directory so your game can find the images
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})