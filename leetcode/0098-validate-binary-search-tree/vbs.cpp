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
#include <limits.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct node_bounds
{
    long long lower;
    long long upper;
};


bool dfs(TreeNode *root, node_bounds bounds )
{
    if( root == nullptr )
        return true;

    if( root->val <= bounds.lower )
        return false;
    else if ( root->val >= bounds.upper )
        return false;

    bool left_valid  = dfs( root->left,  { bounds.lower, root->val });
    bool right_valid = dfs( root->right, { root->val,    bounds.upper });

    return (left_valid && right_valid );
}

bool isValidBST(TreeNode *root)
{
    return dfs( root, { LLONG_MIN, LLONG_MAX });
}


TreeNode *buildTree(std::vector<std::optional<int>> values)
{
    TreeNode *root = new TreeNode(values[0].value() );
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    int index=0;
    while(index<values.size())
    {
        TreeNode *current = bqueue.front();
        bqueue.pop();
        if( values[index].has_value())
        {
            TreeNode *left = new TreeNode( values[index].value() );
            current->left = left;
            bqueue.push(left);
        }
        index++;
        if( (index < values.size()) && ( values[index].has_value()))
        {
            TreeNode *right = new TreeNode( values[index].value() );
            current->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #53 - Maximum Subarray" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {2,1,3};
        int expected = true;
        TreeNode *root = buildTree(nums);
        int result = isValidBST(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums = {5,1,4,std::nullopt,std::nullopt,3,6};
        int expected = false;
        TreeNode *root = buildTree(nums);
        int result = isValidBST(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
