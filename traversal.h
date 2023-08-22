//
// Created by DhawalP on 21/08/23.
//

#ifndef BINARYTREE_TRAVERSAL_H
#define BINARYTREE_TRAVERSAL_H

#endif //BINARYTREE_TRAVERSAL_H
#pragma once
#include <iostream>
#include "binarytree.h"
#include "binaryTree_func.h"
tt
void preOrder(btNode<T>*root)
{
    if(!root) return;
    co<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
tt
void postOrder(btNode<T>*root)
{
    if(!root) return;
    if(root->left) postOrder(root->left);
    if(root->right) postOrder(root->right);
    co<<root->data<<" ";
}
tt
void inOrder(btNode<T>* root,std::vector<int>&a)
{
    if(!root) return;
    inOrder(root->left,a);
    co<<root->data<<" ";
    inOrder(root->right,a);

}