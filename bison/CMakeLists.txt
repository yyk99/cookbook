#
#
#
project(bison_cookbook)
cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if (MSVC)
    add_compile_options(
            "-D_CRT_NONSTDC_NO_WARNINGS" 
            "-D_CRT_SECURE_NO_WARNINGS"
            "/wd4065"
            "/wd4005"
            "/wd4244"
            "/Zc:__cplusplus"
        )
endif()

find_package(FLEX REQUIRED)

option (USE_REFLEX "Use Re-Flex as a lexical scanner" OFF)
if (USE_REFLEX)
	find_package(REFLEX REQUIRED)
	set(FLEX_EXECUTABLE Reflex::Reflex)
endif()

add_subdirectory(simple_scanner)
add_subdirectory(double_points)
add_subdirectory(model12d)