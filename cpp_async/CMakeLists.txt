#
#
#

project (cpp_async)

add_executable(async1 async1.cpp)

if (WIN32)
	add_subdirectory(MFC)
endif()
