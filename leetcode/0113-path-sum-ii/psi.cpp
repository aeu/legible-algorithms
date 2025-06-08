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


void dfs(TreeNode *root,
         std::vector<std::vector<int>> &paths,
         std::vector<TreeNode *> &current_path,
         int sum,
         int target_sum)
{
    if( root == nullptr )
        return;
    current_path.push_back(root);
    sum += root->val;
    if(( root->left == nullptr ) && ( root->right == nullptr ))
    {
        if( sum == target_sum )
        {
            std::vector<int> sumpath;
            for(const auto &curr : current_path )
            {
                sumpath.push_back(curr->val);
            }
            paths.push_back(sumpath);
        }
    }
    else
    {
        dfs(root->left,paths,current_path,sum,target_sum);
        dfs(root->right,paths,current_path,sum,target_sum);
    }
    current_path.pop_back();
}


std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
{
    std::vector<std::vector<int>> paths;
    std::vector<TreeNode *> current_path;
    dfs(root,paths,current_path,0,targetSum);
    return paths;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int targetSum = 22;
        std::vector<std::optional<int>> values = { 5,4,8,11,std::nullopt,13,4,7,2,std::nullopt,std::nullopt,5,1 };
        TreeNode *root = buildTree(values);
        std::vector<std::vector<int>> expected = {{5,4,11,2},{5,8,4,5}};
        std::vector<std::vector<int>>  result = pathSum(root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int targetSum = 5;
        std::vector<std::optional<int>> values = { 1,2,3};
        TreeNode *root = buildTree(values);
        std::vector<std::vector<int>> expected = {};
        std::vector<std::vector<int>>  result = pathSum(root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int targetSum = 0;
        std::vector<std::optional<int>> values = { 1,2 };
        TreeNode *root = buildTree(values);
        std::vector<std::vector<int>> expected = {};
        std::vector<std::vector<int>>  result = pathSum(root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
