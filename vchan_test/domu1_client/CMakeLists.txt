cmake_minimum_required(VERSION 3.0)
project(domu1_client)

add_executable(domu1_client domu1_client.cpp)
target_link_libraries(domu1_client xenvchan pthread)
