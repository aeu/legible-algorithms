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


TreeNode *searchBST(TreeNode *root,
                    int val)
{
    if( root == nullptr )
        return nullptr;

    if( root->val == val )
        return root;

    if( val < root->val )
        return searchBST( root->left,val);
    
    return searchBST(root->right,val);
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #700 - Search in a Binary Search Tree" << std::endl;
    {
        int seek_value = 2;
        std::vector<std::optional<int>> values = { 4,2,7,1,3};
        std::cout << "Searching for : " << seek_value << " in : ";
        TreeNode *root = buildTree(values);
        TreeNode *found_root = searchBST(root,seek_value);
    }
    {
        int seek_value = 5;
        std::vector<std::optional<int>> values = { 4,2,7,1,3};
        std::cout << "Searching for : " << seek_value << " in : ";
        TreeNode *root = root = buildTree(values);
        TreeNode *found_root = searchBST(root,seek_value);
    }
    return -1;
}
