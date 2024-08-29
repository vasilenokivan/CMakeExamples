cmake_minimum_required(VERSION 3.5)

project(main)

#Add sub directories
add_subdirectory(sub_project1) #указывает на директорию в которой обязательно должен быть наличие CMakeLists.txt
add_subdirectory(sub_project2)
add_subdirectory(main)
