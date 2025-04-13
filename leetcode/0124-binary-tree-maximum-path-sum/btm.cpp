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
#include <unordered_map>
#include <stack>
#include <limits.h>

int doWork()
{
    return 1;
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



int dfs(TreeNode *root, int &max_path_found )
{
    if( root == nullptr )
        return 0;

    int lpsum = std::max( 0, dfs( root->left,  max_path_found ));
    int rpsum = std::max( 0, dfs( root->right, max_path_found ));

    int path_through_me = root->val + lpsum + rpsum;
    max_path_found = std::max( max_path_found, path_through_me );

    return root->val + std::max(lpsum,rpsum);
}

int maxPathSum(TreeNode* root)
{
    int max_path_found = INT_MIN;
    dfs( root,max_path_found );
    return max_path_found;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC124 - Binary Tree Maximum Path Sum" << std::endl << std::endl;
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
    return 0;
}
