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


void inOrder(TreeNode *root,
             std::vector<TreeNode *> &io_path)
{
    if( root == nullptr )
        return;


    inOrder(root->left,io_path);
    io_path.push_back( root );
    inOrder(root->right,io_path);
}

TreeNode* increasingBST(TreeNode* root)
{
    std::vector<TreeNode *> io_path;
    inOrder(root,io_path);
    if( io_path.size() == 0 )
        return nullptr;
    TreeNode *prev = io_path[0];
    for(int index=1;index<io_path.size();index++)
    {
        io_path[index]->left  = nullptr;
        io_path[index]->right = nullptr;
        prev->left = nullptr;
        prev->right = io_path[index];
        prev = io_path[index];
        
    }
    return io_path[0];
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0897-increasing-order-search-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {5,3,6,2,4,std::nullopt,8,1,std::nullopt,std::nullopt,std::nullopt,7,9};
        TreeNode *root = buildTree(nums);
        TreeNode *newroot = increasingBST(root);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
