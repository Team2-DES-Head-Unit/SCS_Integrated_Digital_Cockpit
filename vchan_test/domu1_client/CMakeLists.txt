cmake_minimum_required(VERSION 3.10)
project(domu1_client)

find_library(XENVCHAN NAMES xenvchan libxenvchan.so REQUIRED)
find_package(Threads REQUIRED)

add_executable(domu1_client domu1_client.cpp)
target_link_libraries(domu1_client
    ${XENVCHAN}
    ${CMAKE_THREAD_LIBS_INIT}
)

