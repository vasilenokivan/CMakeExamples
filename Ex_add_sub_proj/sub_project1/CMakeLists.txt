cmake_minimum_required(VERSION 3.5)

#set the project name
project(sublibrary_c)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

#Add a library with the above sources
add_library(${PROJECT_NAME} src/sub_c.c)	#указываем, что это будет библиотека
add_library(sub::lib_c ALIAS ${PROJECT_NAME}) 	#указываем, что это будем псевдоним для библиотеки

target_include_directories( ${PROJECT_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}/include    #указываем где лежат хедеры
)
