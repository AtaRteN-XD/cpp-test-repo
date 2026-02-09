cmake_minimum_required(VERSION 3.10) #Минимальная версия CMake

project(Calculator) #Имя проекта

#Используемые файлы для компиляции
set(SOURCE_FILES
	src/main.cpp
	src/calculator.cpp
	src/calculator.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}) #Создание исполняемого файла из main.cpp