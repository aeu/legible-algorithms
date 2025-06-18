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

struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dumpNodeList(std::vector<TreeNode *> values)
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

struct BfsInfo
{
    int current_depth;
    TreeNode *current_node;
};

bool isCousins(TreeNode *root, int x, int y )
{
    BfsInfo b_info;
    int x_depth = INT_MIN;
    int y_depth = INT_MIN;
    b_info.current_depth = 0;
    b_info.current_node = root;
    std::queue<BfsInfo> bfs_queue;
    bfs_queue.push( b_info );
    BfsInfo curr;
    while( ! bfs_queue.empty() )
    {
        curr = bfs_queue.front();
        bfs_queue.pop();
        if( curr.current_node->val == x )
        {
            x_depth = curr.current_depth;
        }
        else if( curr.current_node->val == y )
        {
            y_depth = curr.current_depth;
        }
        if( ( x_depth != INT_MIN ) && ( y_depth != INT_MIN ) && ( y_depth == x_depth ))
        {
            return true;
        }
        if( curr.current_node->left != nullptr )
        {
            bfs_queue.push( { curr.current_depth+1, curr.current_node->left } );
        }
        if( curr.current_node->right != nullptr )
        {
            bfs_queue.push( { curr.current_depth+1, curr.current_node->right } );
        }
    }
    if(( x_depth != INT_MIN ) && ( y_depth != INT_MIN ) && ( y_depth == x_depth ))
    {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0993-cousins-in-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {1,2,3,4};
        int x = 4;
        int y = 3;
        bool expected = false;
        TreeNode *root = buildTree(nums);
        bool result = isCousins(root,x,y);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1,2,3,std::nullopt,4,std::nullopt,5};
        int x = 5;
        int y = 4;
        bool expected = true;
        TreeNode *root = buildTree(nums);
        bool result = isCousins(root,x,y);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
