cmake_minimum_required(VERSION 3.10)
project(dom0_server)

find_library(XENVCHAN NAMES xenvchan libxenvchan.so REQUIRED)
find_package(Threads REQUIRED)

add_executable(dom0_server dom0_server.cpp)
target_link_libraries(dom0_server
    ${XENVCHAN}
    ${CMAKE_THREAD_LIBS_INIT}
)

