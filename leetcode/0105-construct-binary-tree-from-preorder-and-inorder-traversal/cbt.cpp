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
#include <unordered_map>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} ;
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {} ;
};


TreeNode *build(std::vector<int>& preorder,
                std::vector<int>& inorder,
                std::unordered_map<int,int> &inorder_indexes,
                int &current_preorder_index,
                int range_start,
                int range_end)
{
    if( range_start > range_end )
        return nullptr;

    int root_value = preorder[current_preorder_index++];
    TreeNode *root = new TreeNode(root_value);

    int inorder_index = inorder_indexes[root_value];
    int left_range_end = inorder_index-1;
    int right_range_start = inorder_index+1;
    root->left  = build( preorder,inorder,inorder_indexes,current_preorder_index,range_start, left_range_end);
    root->right = build( preorder,inorder,inorder_indexes,current_preorder_index,right_range_start, range_end);
    
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder,
                    std::vector<int>& inorder)
{
    std::unordered_map<int,int> inorder_indexes;
    for(int index = 0;index<inorder.size();index++)
    {
        inorder_indexes[inorder[index]] = index;
    }
    int current_preorder_index = 0;

    int range_start = 0;
    int range_end = inorder.size()-1;
    
    TreeNode *root = build( preorder,inorder, inorder_indexes, current_preorder_index, range_start, range_end);
    return root;
}




int main(int argc, char **argv)
{
    std::cout << "Leetcode #105 - Construct Binary Tree from Preorder and Inorder Traversal" << std::endl;
    int test_case = 1;
    {
        // std::vector<int> preorder = { 3,9,20,15,7};
        // std::vector<int> inorder = { 9,3,15,20,7};
        
        // std::vector<int> numbers = { 2,7,11,15 };
        // std::vector<int> expected = { 1, 2 };
        // int target = 9;
        // std::vector<int> result = twoSum(numbers, target);
        // std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return -1;
}
