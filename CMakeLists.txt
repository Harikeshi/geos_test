cmake_minimum_required(VERSION 3.13)
#-----------------------------------------------
project(geos_test)
#-----------------------------------------------
set(CORE_MAJOR_VERSION 1)
set(CORE_MINOR_VERSION 0)
set(CORE_PATCH_VERSION 0)
#-----------------------------------------------
cmake_policy(SET CMP0074 NEW)
#-----------------------------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#-----------------------------------------------
option(BUILD_TESTS "Build test wirth gtest" ON)
#-----------------------------------------------
set(CMAKE_DEBUG_POSTFIX "_d")
#-----------------------------------------------
file(GLOB SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
#-----------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCE} ${INCLUDE})
#-----------------------------------------------
find_package(Git)
#-----------------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC geos gtest)
#-----------------------------------------------
if(NOT ${GTEST_FOUND})
    mark_as_afvanced(
    gmock_build_samples
    gtest_build_samples
    gtest_build_tests
    gtest_disable_pthreads
    gtest_force_shared_crt
    )
endif()
#-----------------------------------------------
if(${BUILD_TESTS})
    enable_testing()
    message(STATUS "[${PROJECT_NAME}] Build tests: ON")
else()
    message(STATUS "[${PROJECT_NAME}] Build tests: OFF")
endif()
#-----------------------------------------------
add_subdirectory(3rdparty/)
add_subdirectory(dependencies/)
add_subdirectory(tests/)
