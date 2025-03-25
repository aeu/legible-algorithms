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


bool dfs(TreeNode *root,
         int targetSum,
         std::vector<TreeNode *> &path)
{
    if( root == nullptr )
        return false;
    path.push_back(root);
    if(( root->left == nullptr ) && ( root->right == nullptr ))
    {
        int path_sum = 0;
        for( auto current : path )
        {
            path_sum += current->val;
        }
        path.pop_back();
        return ( path_sum == targetSum );
    }
    bool has_path = ( dfs(root->left, targetSum, path ) || dfs(root->right, targetSum, path ));
    path.pop_back();
    return has_path;
}


bool hasPathSum(TreeNode* root, int targetSum)
{
    std::vector<TreeNode *> path;
    return dfs( root, targetSum, path );
}

TreeNode *buildTree(std::vector<std::optional<int>> root)
{
    std::queue<TreeNode *> build_queue;
    int index=1;
    TreeNode *tree = new TreeNode(root[0].value() );
    build_queue.push(tree);
    while(index<root.size())
    {
        TreeNode *current = build_queue.front();
        build_queue.pop();
        if( root[index].has_value() )
        {
            TreeNode *left = new TreeNode( root[index].value());
            current->left = left;
            build_queue.push(left);
        }
        index++;
        if( ( index < root.size() ) && ( root[index].has_value()))
        {
            TreeNode *right = new TreeNode( root[index].value());
            current->right = right;
            build_queue.push(right);
        }
        index++;
    }       
    return tree;

}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #112 - Path Sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> root = { 5,4,8,11,std::nullopt,13,4,7,2,std::nullopt,std::nullopt,std::nullopt,1};
        int targetSum = 22;
        bool expected = true;
        TreeNode *tree_root = buildTree(root);
        bool result = hasPathSum(tree_root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> root = {1,-2,-3,1,3,-2,std::nullopt,-1};
        int targetSum = 3;
        bool expected = false;
        TreeNode *tree_root = buildTree(root);
        bool result = hasPathSum(tree_root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }



    
    return -1;
}
