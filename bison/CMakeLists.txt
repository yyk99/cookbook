#
#
#
project(bison_cookbook)
cmake_minimum_required(VERSION 3.18)

find_package(FLEX REQUIRED)

option (USE_REFLEX "Use Re-Flex as a lexical scanner" OFF)
if (USE_REFLEX)
	find_package(REFLEX REQUIRED)
	set(FLEX_EXECUTABLE Reflex::Reflex)
endif()

add_subdirectory(simple_scanner)
add_subdirectory(double_points)
