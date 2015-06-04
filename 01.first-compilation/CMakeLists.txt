project(FPS)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

aux_source_directory(. SRC_LIST)
find_package(Irrlicht REQUIRED)
find_package(Bullet REQUIRED)

set(COMMON_SOURCES
common/config.h
common/config.cpp
)

set(CLIENT_SOURCES
${COMMON_SOURCES}
client/shader/shaderwall.frag
client/shader/shaderwall.vert
client/shaderwall.h
client/shaderwall.cpp
client/main.cpp
)

set(SERVER_SOURCES
${COMMON_SOURCES}
server/server.h
server/server.cpp
server/main.cpp
)


add_executable(client ${CLIENT_SOURCES})
add_executable(server ${SERVER_SOURCES})

target_include_directories(client PRIVATE ${Irrlicht_INCLUDE_DIRS})
target_include_directories(client PRIVATE ${BULLET_INCLUDE_DIRS})
target_link_libraries(client ${Irrlicht_LIBRARIES})
target_link_libraries(client ${BULLET_LIBRARIES})

message("--> ${Irrlicht_INCLUDE_DIRS}")

