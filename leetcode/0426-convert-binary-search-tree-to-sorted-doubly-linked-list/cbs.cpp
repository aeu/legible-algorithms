// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


void dumpNodeList(std::vector<Node *> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << "->" ;
        first = false;
        std::cout << curr->val;
    }
    std::cout << std::endl;
}


Node *buildTree(std::vector<std::optional<int>> tree_values)
{
    Node *root = new Node(tree_values[0].value());
    std::queue<Node *>bqueue;
    int index=1;
    bqueue.push(root);
    while( index < tree_values.size() )
    {
        Node *curr = bqueue.front();
        bqueue.pop();
        if( tree_values[index].has_value() )
        {
            Node *left = new Node( tree_values[index].value() );
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            Node *right = new Node( tree_values[index].value() );
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}



void dfs(Node *root,
         std::vector<Node *> &path)
{
    if( root == nullptr )
        return;

    if( root->left != nullptr )
        dfs(root->left,path);

    path.push_back(root);
    //    std::cout << root->val << "->";

    if( root->right != nullptr )
        dfs(root->right,path);
}

Node *treeToDoublyList(Node *root)
{
    if( root == nullptr )
        return nullptr;
    std::vector<Node *> path;
    dfs(root,path);
    Node *node;
    for(int index=0;index<path.size();index++)
    {
        node = path[index];
        if( index > 0 )
        {
            node->left = path[index-1];
        }
        if( index < path.size() - 1 )
        {
            node->right = path[index+1];
        }
        if( index == 0 )
        {
            node->left = path[path.size()-1];
        }
        if( index == path.size() - 1 )
        {
            node->right = path[0];
        }
    }
    return path[0];
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0426-convert-binary-search-tree-to-sorted-doubly-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {4,2,5,1,3};
        Node *root = buildTree(nums);
        treeToDoublyList(root);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
