cmake_minimum_required(VERSION 3.5) #

project(cmake_example_2)

set (cmake_example_2_VERSION_MAJOR 0) # стандартный вариант указания версионности для cmake
set (cmake_example_2_VERSION_MINOR 9) 
set (cmake_example_2_VERSION_PATCH 3) 
set (cmake_example_2_VERSION_TWEAK 4) 
# установка значения переменной
set (cmake_example_2_VERSION "${cmake_example_2_VERSION_MAJOR}.${cmake_example_2_VERSION_MINOR}.${cmake_example_2_VERSION_PATCH}.${cmake_example_2_VERSION_TWEAK}") 

set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -std=c++ly -Wall")

file(GLOB
         CPP_SOURCES "src/*.cpp") #взять все файлы с расширением cpp из src/ и обьединить в переменную CPP_SOURCES. Хедеры указывать не нужно

#указываем файлы, которые нам нужно генерировать
configure_file(
		"${PROJECT_SOURCE_DIR}/include/ver.h.in" 	#это входящий файл
		"${PROJECT_BINARY_DIR}/version.h"		#это файл получаемый на выходе
	      )     

configure_file(
		"${PROJECT_SOURCE_DIR}/include/path.h.in"	#это входящий файл
		"${PROJECT_BINARY_DIR}/path.h"			#это файл получаемый на выходе
	      )   
	      
         
include_directories("${PROJECT_SOURCE_DIR}/include") # указываем директории где будут лежать хедеры
include_directories("${PROJECT_BINARY_DIR}") 	     # указываем директорию где будет лежать bin-файлы
         
add_executable(${PROJECT_NAME} ${CPP_SOURCES}) 	     #собрать исполняемый файл       
      
