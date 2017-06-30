cmake_minimum_required(VERSION 3.7)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp User.cpp User.h Menu.cpp Menu.h MenuInteractionHandler.cpp MenuInteractionHandler.h)

add_executable(lab1 ${SOURCE_FILES})