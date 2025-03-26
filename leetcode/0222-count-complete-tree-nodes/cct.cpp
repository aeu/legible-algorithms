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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<std::optional<int>> nums )
{
    if( nums.size() == 0 )
        return nullptr;
    int index=1;
    TreeNode *root = new TreeNode(nums[0].value());
    std::queue<TreeNode *> bqueue;
    bqueue.push( root );
    while( index < nums.size() )
    {
        TreeNode *current = bqueue.front();
        bqueue.pop();
        if( nums[index].has_value())
        {
            TreeNode *left = new TreeNode(nums[index].value());
            current->left = left;
            bqueue.push(left);
        }
        index++;
        if(( index < nums.size()) && ( nums[index].has_value()))
        {
            TreeNode *right = new TreeNode(nums[index].value());
            current->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}

TreeNode *dfs(TreeNode *root, std::unordered_set<TreeNode *> &seen)
{
    if( root == nullptr )
        return nullptr;
    seen.insert(root);
    if( root->left != nullptr )
        dfs(root->left,seen);
    if( root->right != nullptr )
        dfs(root->right,seen);
    return root;
}

int countNodes(TreeNode* root)
{
    std::unordered_set<TreeNode *>seen;
    dfs(root,seen);
    return seen.size();
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #222 - Count Complete Tree Nodes" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {1,2,3,4,5,6};
        TreeNode *root = buildTree(nums);
        
        int expected = 6;
        int result = countNodes(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums = {};
        TreeNode *root = buildTree(nums);
        
        int expected = 0;
        int result = countNodes(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums = {1};
        TreeNode *root = buildTree(nums);
        
        int expected = 1;
        int result = countNodes(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
