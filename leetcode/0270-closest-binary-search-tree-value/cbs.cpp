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
#include <float.h>
#include <cmath>


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


void dfs(TreeNode *root, double target, double &difference, int &retval)
{
    if( root == nullptr )
        return;
    double abs_difference = fabs((double) root->val - target);
    if( abs_difference < difference )
    {
        retval = root->val;
        difference = abs_difference;
    }
    dfs(root->left,  target, difference, retval );
    dfs(root->right, target, difference, retval );
}


int closestValue(TreeNode *root, double target)
{
    double difference = DBL_MAX;
    int retval;
    dfs(root,target,difference,retval);
    return retval;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0270-closest-binary-search-tree-value" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {4,2,5,1,3};
        TreeNode *root = buildTree(nums);
        float target = 3.713;
        int expected = 4;
        int result = closestValue(root,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums = {1};
        TreeNode *root = buildTree(nums);
        float target = 4.428571;
        int expected = 1;
        int result = closestValue(root,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
