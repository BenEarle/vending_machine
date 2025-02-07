cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(test_proj)

############################
###  Configured Headers  ###
############################


#####################################
###  Global Compiler Definitions  ###
#####################################


##########################
###  Dependency Setup  ###
##########################
include(deps/cadmium2.cmake) 						# Downloads cadmium and sets up variables for includes
include(deps/cadmium2_testing_framework.cmake) 


##########################
###  Global Variables  ###
##########################
set(includes_list 
	"${CADMIUM2_INCLUDE_DIR}"
	"${CADMIUM2_TESTING_FRAMEWORK_INCLUDE_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/deps"
	${CMAKE_CURRENT_SOURCE_DIR}/include
	CACHE STRING "Test program Includes List"
)

#################################
###  Compiler Specific Fixes  ###
#################################


########################
###  Subdirectories  ###
########################ddddddddddddddddddddddddddddddddddddd

add_subdirectory(test)
add_subdirectory(src)
