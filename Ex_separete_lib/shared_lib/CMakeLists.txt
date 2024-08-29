cmake_minimum_required(VERSION 3.5) #

project(cmake_example_4_shared)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
      
 #------------------ Create a library---------------------------
#Generate the shared library form the library sources
#--------------------------------------------------------------
include_directories("${PROJECT_SOURCE_DIR}/include") 	# указываем директории где будут лежать хедеры

add_library(${PROJECT_NAME}_lib 
	     SHARED   					# сделать динамическую библиотеку SHARED. Имя библиотеки будет ${PROJECT_NAME}_lib
	    	src/sLibrary.cpp			# вот из этих исходных файлов	
	    )


	     
