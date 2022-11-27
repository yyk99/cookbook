#
#
#

message(STATUS "REFLEX_FOUND=${REFLEX_FOUND}")
message(STATUS "FLEX_FOUND=${FLEX_FOUND}")

if ( NOT REFLEX_FOUND)
	message (STATUS "No re-flex. {CMAKE_CURRENT_SOURCE_DIR) is skipped.")
	return()
endif()

BISON_TARGET(parser12d
    parser12d.yy
    ${CMAKE_CURRENT_BINARY_DIR}/parser12d.cpp
    COMPILE_FLAGS "-t -v"
)

set(FLEX_FLAGS "--flex")

FLEX_TARGET(parser12d
    scanner12d.ll
    scanner12d.cpp
    COMPILE_FLAGS "${FLEX_FLAGS}"
    DEFINES_FILE "scanner12d.h"
    )
#ADD_FLEX_BISON_DEPENDENCY(lexer parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "lexer: ${FLEX_parser12d_OUTPUTS}")
message(STATUS "BISON_VERSION=${BISON_VERSION}")
message(STATUS "parser: ${BISON_parser12d_OUTPUTS}")

add_executable(model12d
    driver12d.cpp
    driver12d.h
    parser12d.yy
    scanner12d.ll
    ${FLEX_parser12d_OUTPUTS}
    ${BISON_parser12d_OUTPUTS}
)

target_link_libraries(model12d
	PRIVATE Reflex::ReflexLibStatic
)
