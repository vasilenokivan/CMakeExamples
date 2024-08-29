cmake_minimum_required(VERSION 3.5) #просто заголовок, признак хорошого тона, если версия будет ниже будет выдано сообщение

# ${PROJECT_NAME}  это макрос, при использовании PROJECT_NAME будет вставляться имя со следующей строки
project(cmake_example_1)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

# установить версию стандарта
#set(CMAKE_CXX_STANDART 11) # типа стандарт c++
# или
#set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -std=c++98") # с помощью передачи флагов компилятору C++
set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -std=c++1y")  # last version C++
	
set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -std=c11")    # c language

#set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -Wall -02") # включить все варнинги, 02 - уровень оптимизации
set(CMAKE_CXX_FLAGG "${CMAKE_CXX_FLAGS} -Wall -02")

#set(SOURCES main.cpp)  # если указывать вот таким вариантом, то нужно прописывать все файлы ручками, в скобках  указваем все файлы
#or
file(GLOB
         CPPS "*.cpp"	# такой вариант гворит о том что все файлы cpp буду найдена и использованы
         CS   "*.c")	# такой вариант гворит о том что все файлы c буду найдена и использованы

# Создать исполняемый файл, бинарник
#add_executable(${PROJECT_NAME} main.cpp)	#таким макаром нужно добавлять в ручную
#add_executable(${PROJECT_NAME} ${SOURCES})	#таким через переменную описанную выше SOURCES 
#or
add_executable(${PROJECT_NAME} ${CPPS} ${CS}) 	#с помощью регулярного выражения все файлы будут добавлены
