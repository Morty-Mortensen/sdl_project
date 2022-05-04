cmake_minimum_required(VERSION 3.23.1)
set(CMAKE_BUILD_TYPE Debug)
project(sdl_project)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} 
src/main.cpp 
src/network/Producer.cpp 
src/network/Producer.h 
src/network/Consumer.cpp 
src/network/Consumer.h
src/files/Reader.cpp 
src/files/Reader.h
src/outputs/Outputer.cpp 
src/outputs/Outputer.h
)