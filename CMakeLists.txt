
cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER /home/huashi/mysoft/a40i-hmi/ext-toolchain-it7070ei/bin/arm-linux-gnueabihf-gcc)
# set(CMAKE_CXX_COMPILER /home/huashi/mysoft/a40i-hmi/ext-toolchain-it7070ei/bin/arm-linux-gnueabihf-g++)


project(HSDS C CXX)

# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_FLAGS_RELEASE -Ofast)
# set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")


# set include-dir,library-dir,libraries

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


# include
include_directories(${CMAKE_SOURCE_DIR}/include 
                    ${CMAKE_SOURCE_DIR}/3rd/include)


file(GLOB HSDS_SRC src/*.c)
add_library(hsds SHARED ${HSDS_SRC})


# install
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/dist/${PLATFORM_NAME}")
message("CMAKE_INSTALL_PREFIX is ${CMAKE_INSTALL_PREFIX}")
install(TARGETS hsds
    RUNTIME DESTINATION .
    LIBRARY DESTINATION .
    ARCHIVE DESTINATION .
)





# package
set(CPACK_PACKAGE_NAME "HSDS")
set(CPACK_PACKAGE_VERSION 1.0.0)
set(CPACK_PACKAGE_VENDOR "inovance")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "inovance Description")
set(CPACK_GENERATOR "ZIP")  # 多格式支持
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/packages")
include(CPack)
# include(InstallRequiredSystemLibraries)
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libssl-dev")
# set(CPACK_RPM_PACKAGE_REQUIRES "openssl-devel")
