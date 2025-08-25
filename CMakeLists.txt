cmake_minimum_required(VERSION 4.0)
project(linked_lists C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_lists main.c
        linkedlist.h
        likedlist.c)
