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


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<std::optional<int>> tree_values)
{
    if( tree_values.empty() )
        return nullptr;
    
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

void dfs(TreeNode *root, std::vector<int> &retval)
{
    if( root == nullptr )
        return;

    if( root->left != nullptr )
        dfs(root->left,retval);
    retval.push_back( root->val );
    if( root->right != nullptr )
        dfs(root->right,retval);
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> retval;
    dfs(root, retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0094-binary-tree-inorder-traversal" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {1,std::nullopt,2,3};
        TreeNode *root = buildTree(nums);
        std::vector<int> result = inorderTraversal(root);
        std::vector<int> expected = {1,3,2};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1,2,3,4,5,std::nullopt,8,std::nullopt,std::nullopt,6,7,9};
        TreeNode *root = buildTree(nums);
        std::vector<int> result = inorderTraversal(root);
        std::vector<int> expected = {4,2,6,5,7,1,3,9,8};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {};
        TreeNode *root = buildTree(nums);
        std::vector<int> result = inorderTraversal(root);
        std::vector<int> expected = {};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1};
        TreeNode *root = buildTree(nums);
        std::vector<int> result = inorderTraversal(root);
        std::vector<int> expected = {1};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
