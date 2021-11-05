cmake_minimum_required(VERSION 3.20.0)

project(AuroraSpeak VERSION 1.0.1 DESCRIPTION "Aurora Speak Compiler")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

option(DEBUG "On for Debug build, Off for Release build" ON)

# Include external library headers
set(INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")
include_directories(${INCLUDE_DIRS})

if(WIN32)
	# Link libraries for Windows32 or 64 bit builds
	# 64 bit
	if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
		if(DEBUG)
		# Adds to list of folders to search for library
#			list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/x64/Debug/")
		# Links library
#			set(CRYPTOPP_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/Debug/.lib")
		else()
#			list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/x64/Release/")
#			set(CRYPTOPP_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/Release/.lib")
		endif()
	# 32 bit
	else ()
		if(${DEBUG})
#			list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/Win32/Debug/")
#			set(CRYPTOPP_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/Win32/Debug/.lib")
		else()
#			list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/Release/Debug/")
#			set(CRYPTOPP_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/Win32/Release/.lib")
		endif()
	endif ()
endif()

add_executable(${PROJECT_NAME})
add_subdirectory(src)
#target_link_libraries(${PROJECT_NAME} ${CRYPTOPP_LIBRARIES})