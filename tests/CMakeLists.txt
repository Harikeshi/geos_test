project(Tests)
#----------------------------------------------------
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#----------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
#----------------------------------------------------
target_include_directories(${PROJECT_NAME}
PUBLIC
${GTEST_INCLUDE_DIRS} ../src)
#----------------------------------------------------
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
#----------------------------------------------------
