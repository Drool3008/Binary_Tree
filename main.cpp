#include <iostream>
#include "binarytree.h"
#include "traversal.h"
#include "binaryTree_func.h"
#include <vector>
int main() {
    /*
    btNode<int>* head = new btNode<int>(1);
    auto left = new btNode<int>(2);
    auto right = new btNode<int>(3);
    head->left=left;
    head->right=right;
    func<int>::print_recursive(head);
    delete head;
    */


    /*
    btNode<int> * root = func<int>::take_input_recursive();
    func<int>::print_recursive(root);
    */

    auto p = func<int>::take_input_level_wise();
    func<int>::print_level_wise(p);
    /*
    co<<nl;
    //co<<"Printing all nodes at level 3 : ";
    //func<int>::print_all_nodes_at_level_k(p,3);
    co<<nl;
    //co<<"Level order traversal : ";
    //func<int>::level_order_traversal(p);
    co<<func<int>::count_nodes(p)<<nl;
    preOrder(p);
    co<<nl;
    postOrder(p);
    co<<nl;
    std::vector<int> ans;
    inOrder(p,ans);
    co<<nl;
     */


    /*
    co<<nl<<func<int>::max_height(p);
    if(func<int>::is_Symmetric(p)) co<<"\nSymmetric\n";
    else co<<"\nNot Symmetric\n";
    if(func<int>::is_node_present(p,10)) co<<"\n10 is present\n";
    else co<<"\n10 is absent";
    co<<"\nMin value in the tree is : "<<func<int>::min_value(p);
    co<<"\nMax value in the tree is : "<<func<int>::max_value(p);
    co<<"\nNumber of leaf nodes in the tree are : "<<func<int>::count_leaf_nodes(p);
    // Check all functions from bool symmetric
     */
    co<<nl;
    func<int>::print_all_nodes_at_level_k(p,2);
    co<<nl;
    co<<func<int>::found_at_depth(p,8);
    co<<nl;
    std::vector<int> a;
    func<int>::root_to_node_path(p,12,a);
    for(auto &i:a) co<<i<<" ";
    co<<nl;
    co<<func<int>::diameter_of_binary_tree(p);
    return 0;
}
