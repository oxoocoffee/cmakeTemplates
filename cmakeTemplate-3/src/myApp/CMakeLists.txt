cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)
set(DESCRIPTION "Client Application")

set(APP_CLIENT_NAME myClient)
 
message(STATUS "= Building ${DESCRIPTION}")

#set( client_SRCS  src/main.cpp
#                  src/foo.cpp )

# Include *.h files to VS or Qt IDE can edit
file(GLOB client_SRCS src/*.cpp include/*.h)

list_files( "${client_SRCS}" )

include_directories(include ../include )

# add the executable
add_executable(${APP_CLIENT_NAME} ${client_SRCS})

target_link_libraries(${APP_CLIENT_NAME} myApplib pthread )

#set_target_properties( ${APP_CLIENT_NAME}
#        PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CAN_CONFIG_BIN_PATH} )

install (TARGETS ${APP_CLIENT_NAME} DESTINATION bin)

