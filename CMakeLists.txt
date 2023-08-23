cmake_minimum_required(VERSION 3.26)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinaryTree main.cpp
        binarytree.h
        binaryTree_func.h
        traversal.h
        vague_BST_functions.h)
