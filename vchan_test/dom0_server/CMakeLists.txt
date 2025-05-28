cmake_minimum_required(VERSION 3.0)
project(dom0_server)

add_executable(dom0_server dom0_server.cpp)
target_link_libraries(dom0_server xenvchan pthread)
