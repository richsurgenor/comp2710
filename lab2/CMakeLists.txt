cmake_minimum_required(VERSION 3.7)
project(lab2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        HomePage.cpp
        HomePage.h
        krs0048_1.cpp
        Menu.cpp
        Menu.h
        MenuInteractionHandler.cpp
        MenuInteractionHandler.h
        User.cpp
        User.h
        WallPage.cpp
        WallPage.h ConcurrencyHandler.cpp ConcurrencyHandler.h)

add_executable(lab2 ${SOURCE_FILES})