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


int findBottomLeftValue(TreeNode* root)
{
    std::queue<BfsInfo> bfs_queue;
    std::unordered_map<int,TreeNode *> left_nodes;
    int max_depth = -1;
    bfs_queue.push({0,root});
    while( !bfs_queue.empty())
    {
        BfsInfo current = bfs_queue.front();
        bfs_queue.pop();
        if( left_nodes.find( current.depth ) == left_nodes.end() )
        {
            max_depth = std::max(max_depth,current.depth);
            left_nodes[current.depth] = current.node;
        }
        if( current.node->left != nullptr )
            bfs_queue.push({current.depth+1, current.node->left});
        if( current.node->right != nullptr )
            bfs_queue.push({current.depth+1, current.node->right});
    }
    if( max_depth != -1 )
    {
        TreeNode *left = left_nodes[max_depth];
        return left->val;
    }
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0513-find-bottom-left-tree-value" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {2,1,3};
        TreeNode *root = buildTree(nums);
        int expected = 1;
        int result = findBottomLeftValue(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1,2,3,4,std::nullopt,5,6,std::nullopt,std::nullopt,7};
        TreeNode *root = buildTree(nums);
        int expected = 7;
        int result = findBottomLeftValue(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
