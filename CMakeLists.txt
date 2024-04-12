# Template for CMakeLists.txt
cmake_minimum_required(VERSION 3.29)

project(personal 
        VERSION 0.1
        LANGUAGES C)


target_include_directories(${PROJECT_NAME} include) # ? xxx

add_library(${PROJECT_NAME} heap.c)
