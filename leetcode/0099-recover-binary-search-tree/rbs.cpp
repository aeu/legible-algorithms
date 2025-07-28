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

void dfs(TreeNode *root,
         std::vector<TreeNode *> &inorder)
{
    if( root == nullptr )
        return;

    if( root->left != nullptr )
        dfs( root->left, inorder );

    inorder.push_back(root);

    if( root->right != nullptr )
        dfs( root->right,inorder );
}

void recoverTree(TreeNode *root)
{
    if( root == nullptr )
        return;

    if( ( root->left == nullptr ) && ( root->right == nullptr ))
        return;
    TreeNode *prev = nullptr;
    std::vector<TreeNode *> inorder;
    dfs(root,inorder);
    dumpNodeList(inorder);

    TreeNode *first = nullptr;
    TreeNode *middle = nullptr;
    TreeNode *last = nullptr;

    for(int index=0;index<inorder.size();index++)
    {
        if( index == 0 )
            continue;
        if( inorder[index-1]->val > inorder[index]->val )
        {
            if( first == nullptr )
            {
                first = inorder[index-1];
                middle = inorder[index];
            }
            else
            {
                last = inorder[index];
            }
        }
    }
    if( last != nullptr )
    {
        auto temp = first->val;
        first->val = last->val;
        last->val = temp;
    }
    else
    {
        auto temp = first->val;
        first->val = middle->val;
        middle->val = temp;
    }
    dumpNodeList(inorder);
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0099-recover-binary-search-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = { 1,3, std::nullopt, std::nullopt, 2 };
        TreeNode *root = buildTree(nums);
        recoverTree(root);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums = { 3,1,4,std::nullopt, std::nullopt, 2 };
        TreeNode *root = buildTree(nums);
        recoverTree(root);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
