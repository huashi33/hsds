cmake_minimum_required(VERSION 3.10.0)
project(hsds)



set(HSDS_SRC src/hsrq.c)
add_library(hsds SHARED ${HSDS_SRC})

add_executable(testrq test/testrq.c)
target_link_libraries(testrq hsds)