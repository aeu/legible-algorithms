// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <stack>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct BfsInfo
{
    int level;
    Node *node;
};
    

Node* connect(Node* root)
{
    if( root == NULL )
        return NULL;
    
    std::queue<BfsInfo> bfs_queue;
    std::vector<BfsInfo> tree_level;
    bfs_queue.push( { 0, root } );
    while ( ! bfs_queue.empty() )
    {
        BfsInfo current_info = bfs_queue.front();
        bfs_queue.pop();
        if(( ! tree_level.empty() ) && ( current_info.level != tree_level[0].level ))
        {
            if( tree_level.size() == 1 )
                tree_level.clear();
            else
            {
                for(int index=0;index<=tree_level.size()-2;index++)
                {
                    tree_level[index].node->next = tree_level[index+1].node;
                }
                tree_level.clear();
            }
        }
        tree_level.push_back( current_info );
        if( current_info.node->left != NULL )
        {
            bfs_queue.push({current_info.level+1,current_info.node->left});
        }
        if( current_info.node->right != NULL )
        {
            bfs_queue.push({current_info.level+1,current_info.node->right});
        }
    }
    if( tree_level.size() >= 2 )
    {
        for(int index=0;index<=tree_level.size()-2;index++)
        {
            tree_level[index].node->next = tree_level[index+1].node;
        }
    }
    return root;
}

Node *buildTree(std::vector<std::optional<int>> nums )
{
    int index=1;
    Node *root = new Node(nums[0].value());
    std::queue<Node *> bqueue;
    bqueue.push( root );
    while( index < nums.size() )
    {
        Node *current = bqueue.front();
        bqueue.pop();
        if( nums[index].has_value())
        {
            Node *left = new Node(nums[index].value());
            current->left = left;
            bqueue.push(left);
        }
        index++;
        if(( index < nums.size()) && ( nums[index].has_value()))
        {
            Node *right = new Node(nums[index].value());
            current->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #33 - Search in Rotated Sorted Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = { 1,2,3 };
        Node *root = buildTree(nums);
        connect(root);
        // int target = 0;
        // int expected = 4;
        // int result = search(nums,target);
        // std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
    {
        std::vector<std::optional<int>> nums = { 1,2,3,4,5,std::nullopt,7 };
        Node *root = buildTree(nums);
        connect(root);
        // int target = 0;
        // int expected = 4;
        // int result = search(nums,target);
        // std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
