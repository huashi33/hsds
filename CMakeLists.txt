# shm_create shm_attach shm_close shm_lock shm_unlock
# sema_create sema_attach sema_close sema_post sema_wait sema_waitfor
# 
cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER /home/huashi/mysoft/a40i-hmi/ext-toolchain-it7070ei/bin/arm-linux-gnueabihf-gcc)
# set(CMAKE_CXX_COMPILER /home/huashi/mysoft/a40i-hmi/ext-toolchain-it7070ei/bin/arm-linux-gnueabihf-g++)
# set(CMAKE_C_STANDARD 11)

project(HSDS C CXX)

# set(CMAKE_CXX_FLAGS_RELEASE -Ofast)
# set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")



# include_directories(${CMAKE_SOURCE_DIR}/base/src)
# add_subdirectory(base)
# add_subdirectory(tool)
# add_subdirectory(demo)

# for test
enable_testing()

# build
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/3rd/include)

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}")
add_subdirectory(src)
add_subdirectory(test)




# for package
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
