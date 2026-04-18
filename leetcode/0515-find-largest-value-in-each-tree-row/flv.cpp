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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<std::optional<int>> tree_values)
{
    TreeNode *root = new TreeNode(tree_values[0].value());
    std::queue<TreeNode *>bqueue;
    int index=1;
    bqueue.push(root);
    while( index < tree_values.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        if( tree_values[index].has_value() )
        {
            TreeNode *left = new TreeNode( tree_values[index].value() );
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( tree_values[index].value() );
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}

struct BfsInfo {
    int depth;
    TreeNode *node;
};


std::vector<int>largestValues(TreeNode* root) 
{
    std::vector<int> largest_values;
    if( root == nullptr )
        return largest_values;
    
    std::queue<BfsInfo> bfs_queue;
    std::unordered_map<int,int> max_values;
    int max_depth = -1;
    bfs_queue.push({0,root});
    while( !bfs_queue.empty())
    {
        BfsInfo current = bfs_queue.front();
        bfs_queue.pop();

        if( max_values.find( current.depth ) != max_values.end())
            max_values[current.depth] = std::max( max_values[current.depth], current.node->val );
        else
            max_values[current.depth] = current.node->val;

        max_depth = std::max(max_depth,current.depth);

        if( current.node->left != nullptr )
            bfs_queue.push({current.depth+1,current.node->left});
        if( current.node->right != nullptr )
            bfs_queue.push({current.depth+1,current.node->right});
    }
    for(int index=0;index<=max_depth;index++)
    {
        largest_values.push_back( max_values[index] );
    }
    return largest_values;
}
 
int main(int argc, char **argv)
{
    std::cout << std::endl << "0515-find-largest-value-in-each-tree-row" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {1,3,2,5,3,std::nullopt,9};
        TreeNode *root = buildTree(nums);
        std::vector<int> expected = { 1,3,9 };
        std::vector<int> result = largestValues(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1,2,3};
        TreeNode *root = buildTree(nums);
        std::vector<int> expected = { 1,3 };
        std::vector<int> result = largestValues(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
