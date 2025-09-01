# find_package(GTest CONFIG REQUIRED)

add_executable(testds testbuf_gtest.cc)
target_link_directories(testds PRIVATE ${CMAKE_INSTALL_PREFIX}/bin)
target_link_directories(testds PRIVATE ${CMAKE_SOURCE_DIR}/3rd/lib)
target_link_libraries(testds hsds gtest_main gtest)


include(GoogleTest)
gtest_discover_tests(testds)



install(TARGETS testds
    EXPORT testds-targets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION bin
)


# add_test(NAME testds1 COMMAND testds "hhh" "3" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds2 COMMAND testds "HELLO" "1" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds3 COMMAND testds "FGRG" "2" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds4 COMMAND testds "GE" "5" WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_test(NAME testds COMMAND testds "hhh" "3")
