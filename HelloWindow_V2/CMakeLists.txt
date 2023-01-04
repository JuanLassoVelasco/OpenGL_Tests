cmake_minimum_required(VERSION 3.15)

project(HelloWindow)

add_executable(${PROJECT_NAME} glad.c main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
