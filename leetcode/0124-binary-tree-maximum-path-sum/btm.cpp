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
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int dfs(TreeNode *root)
{
    if( root == nullptr )
        return 0;

    int left_path_sum  = std::max(0,dfs(root->left));
    int right_path_sum = std::max(0,dfs(root->right));

    int path_through_me = root->val + left_path_sum + right_path_sum;
    
    max_path_found = std::max( max_path_found, path_through_me);

    return root->val + std::max( left_path_sum, right_path_sum );
}


int maxPathSum(TreeNode *root)
{
    int max_path_found = INT_MIN;
    if( root == nullptr )
        return 0;

    max_path_found = std::max(max_path_found, dfs(root));
    return max_path_found;
}

TreeNode *buildTree(std::vector<std::optional<int>> tree_values)
{
    int index = 1;
    std::queue<TreeNode *> builder_queue;
    TreeNode *root = new TreeNode( tree_values[0].value() );
    builder_queue.push(root);
    while( index < tree_values.size() )
    {
        TreeNode *current = builder_queue.front();
        builder_queue.pop();
        if( tree_values[index].has_value() )
        {
            TreeNode *left = new TreeNode( tree_values[index].value() );
            current->left = left;
            builder_queue.push( left );
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( tree_values[index].value() );
            current->right = right;
            builder_queue.push( right );
        }
        index++;
    }
    return root;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #124 - Binary Tree Maximum Path Sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> tree_values = { 1,2,3 };
        int expected = 6;
        TreeNode *tree = buildTree(tree_values);
        int result = maxPathSum(tree);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> tree_values = { -10,9,20,std::nullopt,std::nullopt,15,7};
        int expected = 42;
        TreeNode *tree = buildTree(tree_values);
        int result = maxPathSum(tree);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
