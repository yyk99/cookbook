#
#
#

find_package(FLEX REQUIRED)
#find_package(BISON REQUIRED)

if (WIN32)
    add_definitions(-DYY_NO_UNISTD_H)
endif()

#BISON_TARGET(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
#  COMPILE_FLAGS "-t -v"
#)

FLEX_TARGET(scanner scanner.l scanner.cpp)
#ADD_FLEX_BISON_DEPENDENCY(lexer parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${FLEX_INCLUDE_DIR})

message(STATUS "lexer: ${FLEX_lexer_OUTPUTS}")
message(STATUS "BISON_VERSION=${BISON_VERSION}")
message(STATUS "parser: ${BISON_parser_OUTPUTS}")

add_executable(scanner_app
    scanner.l
    ${FLEX_scanner_OUTPUTS}
    ${BISON_parser_OUTPUTS}
)
