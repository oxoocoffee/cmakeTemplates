cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)
set(DESCRIPTION "App Library")

message(STATUS "= Building ${DESCRIPTION}")

set(APP_LIB_NAME myApplib)

#set(app_SRCS   src/myLib.cpp
#               src/myLibPrivate.cpp )

# Include *.h files to VS or Qt IDE can edit
file(GLOB app_SRCS src/*.cpp include/*.h)

list_files( "${app_SRCS}" )

include_directories(include ../include ${CAN_CONFIG_BIN_INCLUDE})

add_library(${APP_LIB_NAME} ${app_SRCS})

target_include_directories(${APP_LIB_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

set_target_properties(${APP_LIB_NAME}
        PROPERTIES OUTPUT_NAME ${APP_LIB_NAME})

set_target_properties(${APP_LIB_NAME}
        PROPERTIES VERSION 1.0 SOVERSION 1)

set( APP_LIB_CONFIG_NAME ${APP_LIB_NAME})

install(TARGETS ${APP_LIB_NAME}
        EXPORT ${APP_LIB_CONFIG_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/
        DESTINATION include)

install(EXPORT ${APP_LIB_CONFIG_NAME}
        DESTINATION share)


