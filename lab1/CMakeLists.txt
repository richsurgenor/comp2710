cmake_minimum_required(VERSION 3.7)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        krs0048_1.cpp
        Menu.cpp
        MenuInteractionHandler.cpp
        User.cpp WallPage.cpp WallPage.h HomePage.cpp HomePage.h)

add_executable(lab1 ${SOURCE_FILES})