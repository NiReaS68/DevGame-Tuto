project(Irrlicht_Terrain)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Irrlicht REQUIRED)

set(MAIN_SOURCES
main.cpp
)

add_executable(main ${MAIN_SOURCES})

target_include_directories(main PRIVATE ${Irrlicht_INCLUDE_DIRS})
target_link_libraries(main ${Irrlicht_LIBRARIES})
