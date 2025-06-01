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

void buildLeftBoundary(TreeNode *root,
                       std::vector<TreeNode *> &left)
{
    if( root == nullptr )
        return;
    // final leaf nodes are not in left boundary
    if(( root->left == nullptr ) && ( root->right == nullptr ))
        return;

    left.push_back(root);

    if( root->left != nullptr )
        buildLeftBoundary(root->left, left );
    else 
        buildLeftBoundary(root->right, left );
}

void buildRightBoundary(TreeNode *root,
                       std::vector<TreeNode *> &right)
{
    if( root == nullptr )
        return;
    // final leaf nodes are not in the boundary
   if(( root->left == nullptr ) && ( root->right == nullptr ))
        return;

   right.push_back(root);
   
   if( root->right != nullptr )
       buildRightBoundary(root->right, right );
   else
       buildRightBoundary(root->left, right );
}

void buildLeaves(TreeNode *root,
                 std::vector<TreeNode *> &leaves)
{
    if( root == nullptr )
        return;

    buildLeaves(root->left,leaves);
    if( ( root->left == nullptr ) && ( root->right == nullptr ))
        leaves.push_back(root);
    buildLeaves(root->right,leaves);
}


std::vector<int> boundaryOfBinaryTree(TreeNode* root)
{
    std::vector<TreeNode *> left;
    std::vector<TreeNode *> right;
    std::vector<TreeNode *> leaves;
    buildLeftBoundary(root->left,left);
    buildRightBoundary(root->right,right);
    buildLeaves(root,leaves);
    std::reverse(right.begin(),right.end());

    std::vector<int> retval;
    retval.push_back(root->val);
    for(const auto &curr : left )
    {
        retval.push_back(curr->val);
    }
    for(const auto &curr : leaves )
    {
        if( curr != root )
            retval.push_back(curr->val);
    }
    for(const auto &curr : right )
    {
        retval.push_back(curr->val);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0545-boundary-of-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {1,std::nullopt,2,3,4};
        TreeNode *root = buildTree(nums);
        std::vector<int> expected = {1,3,4,2};
        std::vector<int> result = boundaryOfBinaryTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1,2,3,4,5,6,std::nullopt,std::nullopt,std::nullopt,7,8,9,10};
        TreeNode *root = buildTree(nums);
        std::vector<int> expected = {1,2,4,7,8,9,10,6,3};
        std::vector<int> result = boundaryOfBinaryTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
