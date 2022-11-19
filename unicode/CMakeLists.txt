#
#
#

cmake_minimum_required(VERSION 3.18)
project( unicode_bits)

set (TEST_FILES_TXT
	ok-kor-BE.txt
	text-BE.txt
	text-LE.txt
	yyk-BE.txt
	yyk-LE.txt
	yyk-UTF8.txt
	yyk-cp1251.txt
)

add_executable(read_utf16 
	read_utf16.cpp
	${TEST_FILES_TXT}
	)

source_group("Test Files" FILES ${TEST_FILES_TXT})

foreach (txt IN LISTS TEST_FILES_TXT)
	message (STATUS "${txt}")
	configure_file("${txt}" "${txt}" COPYONLY)
endforeach()

add_executable(locale 
	locale.cpp
	${TEST_FILES_TXT}
	)

# end of file

