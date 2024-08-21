cmake_minimum_required(VERSION 3.27)

add_executable(modul_26_task_3 main.cpp
        ${MY_INCLUDE_DIR}/window.h
        window.cpp)
target_include_directories(modul_26_task_3 PUBLIC ${MY_INCLUDE_DIR})