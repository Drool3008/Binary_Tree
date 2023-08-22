//
// Created by DhawalP on 21/08/23.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#endif //BINARYTREE_BINARYTREE_H
#pragma once
#include <iostream>
#define tt template<typename T>
tt
class btNode{
public:
    btNode<T>* left;
    btNode<T>* right;
    T data;

    btNode(int data)
    {
        left=NULL;
        right=NULL;
        this->data=data;
    }
    ~btNode()
    {
        std::cout<<"deleted\n";
        delete left;
        delete right;
    }
};