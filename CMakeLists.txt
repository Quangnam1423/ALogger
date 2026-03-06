##################################################################
## CMakeLists.txt for ALogger root directory.
## @author: Quangnam1423
## @date: 2024-06-01
## @description: This is the main CMakeLists.txt file for the ALogger project.
###################################################################
cmake_minimum_required(VERSION 3.11)


##################################################################
## Project definition.
###################################################################
project(ALogger VERSION 1.0.0 LANGUAGES CXX C)


##################################################################
## Options for build method.
## By default, we build ALogger as a shared library. 
## You can set this option to OFF to build it as a static library.
###################################################################
option(ALOGGER_BUILD_SHARED "Build Alogger as a shared library" ON)

if (ALOGGER_BUILD_SHARED)
    set(ALOGGER_BUILD_TYPE SHARED)
    message(STATUS "Building ALogger as a shared library")
else()
    set(ALOGGER_BUILD_TYPE STATIC)
    message(STATUS "Building ALogger as a static library")  
endif()


##################################################################
## C++ standard.
###################################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


##################################################################
## Output directories for binaries and libraries.
###################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

##################################################################
## Include spdlog as a dependency.
###################################################################
include(FetchContent)
message(STATUS "Loading spdlog...")

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.0
)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Disable spdlog tests" FORCE)
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "Disable spdlog examples" FORCE)

FetchContent_MakeAvailable(spdlog)


##################################################################
## Add subdirectories for ALogger and Test.
###################################################################
add_subdirectory(ALogger)
add_subdirectory(Test)