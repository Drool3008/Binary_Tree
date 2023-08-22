//
// Created by DhawalP on 21/08/23.
//
#pragma once
#ifndef BINARYTREE_BINARYTREE_FUNC_H
#define BINARYTREE_BINARYTREE_FUNC_H

#endif //BINARYTREE_BINARYTREE_FUNC_H
#define nl "\n"
#define co std::cout
#include "binarytree.h"
#include <queue>
tt
class func{
public:
    static void print_recursive(btNode<T>* head)
    {
        if(head==NULL) return;
        co<<head->data<<": ";
        if(head->left) co<<"L"<<head->left->data<<" ";
        if(head->right) co<<"R"<<head->right->data<<" ";
        co<<nl;
        print_recursive(head->left);
        print_recursive(head->right);
    }
    static btNode<T>* take_input_recursive()
    {
        co<<"Enter root data : ";
        int rootData;
        std::cin>>rootData;
        if(rootData==-1) return NULL;
        auto root =new btNode<int>(rootData);
        co<<"Enter left data for "<<root->data<<" : ";
        root->left=take_input_recursive();
        co<<"Enter right data for "<<root->data<<" : ";
        root->right=take_input_recursive();
        return root;
    }

    static btNode<T>* take_input_level_wise()
    {
        co<<"\nEnter root Data : ";
        int rootData;
        std::cin>>rootData;
        if(rootData==-1) return NULL;
        btNode<T>* root = new btNode<T>(rootData);
        std::queue<btNode<T>*> q;
        q.push(root);
        while(!q.empty())
        {
            btNode<T>* f = q.front();
            q.pop();
            co<<"Enter left child for "<<f->data<<" : ";
            T lchild,rchild;
            std::cin>>lchild;
            if(lchild!=-1)
            {
                btNode<T>* left_child=new btNode<T>(lchild);
                f->left=left_child;
                q.push(left_child);
                co<<"Enter right child for "<<f->data<<" : ";
                std::cin>>rchild;
                if(rchild!=-1)
                {
                    btNode<T>* right_child=new btNode<T>(rchild);
                    q.push(right_child);
                    f->right=right_child;
                }
                else
                {
                    f->right=NULL;
                }
            }
            else
            {
                f->left=NULL;
                co<<"Enter right child for "<<f->data<<" : ";
                std::cin>>rchild;
                if(rchild!=-1)
                {
                    btNode<T>* right_child=new btNode<T>(rchild);
                    q.push(right_child);
                    f->right=right_child;
                }
                else
                {
                    f->right=NULL;
                }
            }
        }
        return root;
    }

    static void print_level_wise(btNode<T>* root)
    {
        if(!root)
        {
            co<<"Empty Tree";
            return;
        }
        std::queue<btNode<T>*>q;
        q.push(root);
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            co<<f->data<<" : ";
            if(!f->left) co<<"L:NULL ";
            else
            {
                co<<"L:"<<f->left->data<<" ";
                q.push(f->left);
            }
            if(!f->right) co<<"R:NULL ";
            else
            {
                co<<"R:"<<f->right->data<<" ";
                q.push(f->right);
            }
            co<<nl;
        }
    }

    static void print_all_nodes_at_level_k(btNode<T>* root,int k)
    {
        if(!root) return;
        if(k==0)
        {
            co<<root->data<<" ";
            return;
        }
        print_all_nodes_at_level_k(root->left,k-1);
        print_all_nodes_at_level_k(root->right,k-1);
    }

    static void level_order_traversal(btNode<T>* root)
    {
        if(!root) return;
        std::queue<btNode<T>*> q;
        q.push(root);
        co<<root->data<<" ";
        while(!q.empty())
        {
            auto f =q.front();
            q.pop();
            if(f->left)
            {
                co<<f->left->data<<" ";
                q.push(f->left);
            }
            else co<<"";
            if(f->right)
            {
                co<<f->right->data<<" ";
                q.push(f->right);
            }
            else co<<"";
        }
    }
    static int count_nodes(btNode<T>* root)
    {
        if(!root) return 0;
        if(!root->left && root->right) return 1;
        int l = count_nodes(root->left);
        int r = count_nodes(root->right);
        return 1+l+r;
    }
    static int max_height(btNode<T>* root)
    {
        if(!root) return 0;
        int maxh=0;
        int lh=max_height(root->left);
        int rh= max_height(root->right);
        return 1+std::max(lh,rh);
    }
    static bool fun(btNode<T>*l, btNode<T>*r)
    {
        if(!l && r) return false;
        if(l && !r) return false;
        if(!l && !r) return true;
        if(l->data!=r->data) return false;
        return (fun(l->left,r->right) && fun(l->right,r->left));
    }
    static bool is_Symmetric(btNode<T>* root)
    {
        if(!root) return true;
        return fun(root->left,root->right);
    }
    static bool is_node_present(btNode<T>* root,int k)
    {
        if(!root) return false;
        if(root->data==k) return true;
        bool l= is_node_present(root->left,k);
        bool r= is_node_present(root->right,k);
        return (l||r);
    }
    static int min_value(btNode<T>* root,int m=INT_MAX)
    {
        if(!root) return m;
        if(root->data < m) m=root->data;
        int l = min_value(root->left,m);
        int r= min_value(root->right,m);
        return std::min(l,r);
    }
    static int max_value(btNode<T>* root,int m=INT_MIN)
    {
        if(!root) return m;
        if(root->data> m) m=root->data;
        int l= max_value(root->left,m);
        int r= max_value(root->right,m);
        return std::max(l,r);
    }
    static int count_leaf_nodes(btNode<T>* root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l = count_leaf_nodes(root->left);
        int r = count_leaf_nodes(root->right);
        return l+r;
    }
    static int found_at_depth(btNode<T>* root,int d,int k=-1)
    {
        if(!root) return -1;
        if(root->data == d) return k;
        int l = found_at_depth(root->left,d,++k);
        int r = found_at_depth(root->right,d,++k);
        return std::max(l,r);
    }
    static std::pair<int,int> fun(btNode<T>* root)
    {
        if(!root)
        {
            std::pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }
        std::pair<int,int> l = fun(root->left);
        std::pair<int,int> r = fun(root->right);

        int lh =l.first;
        int rh=r.first;
        int ld=l.second;
        int rd=r.second;
        std::pair<int,int> p;
        p.first=1+std::max(lh,rh);
        p.second=std::max(lh+rh,std::max(ld,rd));
        return p;
    }
    static int diameter_of_binary_tree(btNode<T>* root)
    {
        std::pair<int,int>p =fun(root);
        return p.second;
    }

    static bool root_to_node_path(btNode<T>* root,int target,std::vector<int>& v)
    {
        if(!root) return false;
        v.push_back(root->data);
        if(root->data==target)
        {
            return true;
        }
        bool l = root_to_node_path(root->left,target,v);
        bool r = root_to_node_path(root->right,target,v);
        if(l || r)
        {
            return true;
        }
        else
        {
            v.pop_back();
            return false;
        }
    }
};