cmake_minimum_required(VERSION 3.10)
project(HSDS_TEST C CXX)




if(WIN32)
    if(CMAKE_CL_64)
        set(PLATFORM_NAME "win64")
    else()
        set(PLATFORM_NAME "win32")
    endif()
elseif(UNIX)
    if("${CMAKE_C_COMPILER_TARGET}" STREQUAL "arm-linux-gnueabihf")
        set(PLATFORM_NAME "linux_arm32")
    elseif("${CMAKE_C_COMPILER_TARGET}" STREQUAL "aarch64-linux-gnu")
        set(PLATFORM_NAME "linux_arm64")
    else()
        set(PLATFORM_NAME "linux_x64")
    endif()
elseif(APPLE)
    message("This is macOS.")
endif()

message("CMAKE_C_COMPILER is ${CMAKE_C_COMPILER}")
message("PLATFORM_NAME is ${PLATFORM_NAME}")


set(HSDS_ROOT_DIR ${CMAKE_SOURCE_DIR}/..)
set(TESTDS_LIB_DIR ${HSDS_ROOT_DIR}/dist/${PLATFORM_NAME}
                   3rd/lib/${PLATFORM_NAME})
set(TESTDS_INC_DIR ${HSDS_ROOT_DIR}/include
                   3rd/include )

message("TESTDS_INC_DIR is ${TESTDS_INC_DIR}")
message("TESTDS_LIB_DIR is ${TESTDS_LIB_DIR}")

add_executable(testds testbuf_gtest.cc)
target_include_directories(testds PRIVATE ${TESTDS_INC_DIR})
target_link_directories(testds PRIVATE ${TESTDS_LIB_DIR})
target_link_libraries(testds hsds gtest_main gtest)

enable_testing()
include(GoogleTest)
gtest_discover_tests(testds)


set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/dist/${PLATFORM_NAME}")
install(TARGETS testds
    EXPORT testds-targets
    RUNTIME DESTINATION .
    LIBRARY DESTINATION .
    ARCHIVE DESTINATION .
)


# add_test(NAME testds1 COMMAND testds "hhh" "3" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds2 COMMAND testds "HELLO" "1" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds3 COMMAND testds "FGRG" "2" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds4 COMMAND testds "GE" "5" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds COMMAND testds "hhh" "3")
