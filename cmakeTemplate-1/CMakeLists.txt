# Sample Cmake file for quick C++ project creation
# By Robert J. Gebis (oxoocoffee)

cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( STATUS "In-source builds not allowed. Please make build directory")
    message( STATUS "and run CMake from there")
    message( STATUS "You may need to remove CMakeCache.txt and CmakeFiles/" )
    message( FATAL_ERROR )
endif()

#-----------------------------------------------------------------------
set(PROJ_NAME     "ProjectName-1")
set(COMPANY_NAME  "XYZ LLC")

#-----------------------------------------------------------------------
# The version number is used.
set(APP_VERSION_MAJOR      0)
set(APP_VERSION_MINOR      1)
set(APP_VERSION_PATCH      1)
# This one will be set with git revision
set(APP_VERSION_REVISION   0)

# We set temporary version here since project() must be called
# first to initailize cmake subsystem but we will update version later when we test for git repo version
# In this project we only enabling C++ project (CXX). For C based project replace CXX with C or you can mix CXX C
project(${PROJ_NAME} VERSION "${APP_VERSION_MAJOR}.${APP_VERSION_MINOR}.${APP_VERSION_PATCH}.0" LANGUAGES CXX)

add_definitions(-DQT_NO_KEYWORDS)

# Set this variables since they are not used so cmake will not give you warning like
# CMake Warning:
#   Manually-specified variables were not used by the project:
#
#    CMAKE_C_COMPILER
#    QT_QMAKE_EXECUTABLE

set(ignoreMe "${CMAKE_C_COMPILER} ${QT_QMAKE_EXECUTABLE}")

# Check if the given <include> file may be included in a CXX source
include(CheckIncludeFileCXX)

#-----------------------------------------------------------------------
macro(list_files list)
    if (DEFINE_LIST_SOURCES )
        foreach(infileName ${list})
            message(STATUS " ${infileName}")
        endforeach(infileName)
    endif(DEFINE_LIST_SOURCES)
endmacro()

#-----------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra -Wunused-parameter -Wformat-security -Wunreachable-code -fdata-sections -ffunction-sections -Wcast-align")
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wunused-parameter -Wformat-security -Wunreachable-code -fdata-sections -ffunction-sections -Wcast-align")

set(CMAKE_C_FLAGS_DEBUG   "-O0" CACHE INTERNAL "C debug compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG "-O0" CACHE INTERNAL "C++ debug compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG "-g"  CACHE INTERNAL "ASM debug compiler flags")

set(CMAKE_C_FLAGS_RELEASE   "-Os -flto" CACHE INTERNAL "C release compiler flags")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -flto" CACHE INTERNAL "C++ release compiler flags")
set(CMAKE_ASM_FLAGS_RELEASE ""          CACHE INTERNAL "ASM release compiler flags")

# If cmake -DCMAKE_BUILD_TYPE=[DEBUG|RELEASE] ..
if( NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#-----------------------------------------------------------------------
# Add include folder to compiler search path so foo.h can be found
include_directories(include ../include)

# There are two ways including your sources in project
# Manual or Automatic. In Manual Mode you add files that you want to include
# Automatic will add all cpp files found in src

# Manual
#set(app_SRCS   src/main.cpp
#               src/foo.cpp )

# Automatic
file(GLOB app_SRCS src/*.cpp include/*.h)

list_files( "${app_SRCS}" )

add_executable(${PROJECT_NAME} ${app_SRCS})
