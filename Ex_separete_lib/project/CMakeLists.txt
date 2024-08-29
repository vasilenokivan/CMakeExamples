cmake_minimum_required(VERSION 3.5) #

project(cmake_example_4)

set (${PROJECT_NAME}_VERSION_MAJOR 0) # стандартный вариант указания версионности для cmake, название проекта подставляется автоматически
set (${PROJECT_NAME}_VERSION_MINOR 9) 
set (${PROJECT_NAME}_VERSION_PATCH 3) 
set (${PROJECT_NAME}_VERSION_TWEAK 4) 
# установка значения переменной
set (cmake_example_2_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}.${${PROJECT_NAME}_VERSION_TWEAK}") 

set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -std=c++ly -Wall")

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
 
 
#---------------------Create an executable----------------------------------------
file(GLOB
         CPP_SOURCE "src/*.cpp") #взять все файлы с расширением cpp из src/ и обьединить в переменную CPP_SOURCES. Хедеры указывать не нужно
 
#link_directories(${CMAKE_SOURCE_DIR}/libs/shared)	  	#указываем библиотеки которые будем использовать для связывания
link_directories(${CMAKE_SOURCE_DIR}/libs/static)

add_executable(${PROJECT_NAME} ${CPP_SOURCE})

#target_link_libraries( ${PROJECT_NAME}			#динамическая ликовка
#			cmake_example_4_shared_lib
#)

target_link_libraries( ${PROJECT_NAME}			#статическая линковка
			cmake_example_4_static_lib
)
