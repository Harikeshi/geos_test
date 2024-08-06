#----------------------------------------------------
if(${BUILD_TESTS})
    # git submodules
    if(${GIT_FOUND})
        execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init 3rdparty/gtest
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )
    endif()

    add_subdirectory(gtest)
    set(GTEST_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/gtest/googletest/include" PARENT_SCOPE)
    set(GTEST_LIBRARY "gtest" PARENT_SCOPE)
endif()
#----------------------------------------------------
    if(${GIT_FOUND})
        execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init 3rdparty/geos
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    )

    add_subdirectory(geos)
    set(GEOS_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/geos/include" PARENT_SCOPE)
    set(GEOS_LIBRARY "geos" PARENT_SCOPE)
endif()
#-------------------------------------------------------
