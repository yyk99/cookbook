#
#
#

cmake_minimum_required(VERSION 3.18)
project( unicode_bits)

add_executable(read_utf16 
	read_utf16.cpp
	text-BE.txt
	text-LE.txt
	ok-kor-BE.txt
	)

configure_file(text-BE.txt text-BE.txt COPYONLY)
configure_file(text-LE.txt text-LE.txt COPYONLY)
configure_file(ok-kor-BE.txt ok-kor-BE.txt COPYONLY)

add_executable(locale locale.cpp)

# end of file

