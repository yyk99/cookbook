#
#
#

#find_package(FLEX REQUIRED)
#find_package(BISON REQUIRED)

message(STATUS "REFLEX_FOUND=${REFLEX_FOUND}")
message(STATUS "FLEX_FOUND=${FLEX_FOUND}")

if (WIN32)
    add_definitions(-DYY_NO_UNISTD_H)
endif()

#BISON_TARGET(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
#  COMPILE_FLAGS "-t -v"
#)

set(FLEX_FLAGS "--flex")

FLEX_TARGET(scanner 
    scanner.ll
    scanner.cpp
    COMPILE_FLAGS "${FLEX_FLAGS}"
    )
#ADD_FLEX_BISON_DEPENDENCY(lexer parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "lexer: ${FLEX_lexer_OUTPUTS}")
message(STATUS "BISON_VERSION=${BISON_VERSION}")
message(STATUS "parser: ${BISON_parser_OUTPUTS}")

add_executable(scanner_app
    scanner.ll
    ${FLEX_scanner_OUTPUTS}
    ${BISON_parser_OUTPUTS}
)

target_link_libraries(scanner_app
	PRIVATE Reflex::ReflexLibStatic
	)
