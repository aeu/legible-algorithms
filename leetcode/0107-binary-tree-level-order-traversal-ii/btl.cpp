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
      TreeNode *left;
      TreeNode *right;
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

struct BfsInfo 
{
    int level;
    TreeNode *node;
};

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) 
{
    std::vector<std::vector<int>> retval;
    if( root == nullptr )
        return retval;
    std::queue<BfsInfo> bqueue;
    std::unordered_map<int,std::vector<int>> levels;
    bqueue.push({0,root});
    while( ! bqueue.empty())
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        levels[ curr.level ].push_back( curr.node->val );
        if( curr.node->left != nullptr )
        {
            bqueue.push({curr.level+1,curr.node->left});
        }
        if( curr.node->right != nullptr )
        {
            bqueue.push({curr.level+1,curr.node->right});
        }
    }
    for(int index = levels.size()-1;index>=0;index--)
    {
        std::vector<int> current_level;
        for(const auto curr : levels[index] )
        {
            current_level.push_back( curr );
        }
        retval.push_back(current_level);
    }
    return retval;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {3,9,20,std::nullopt,std::nullopt,15,7};
        TreeNode *root = buildTree(nums);
        std::vector<std::vector<int>> expected = {{15,7},{9,20},{3}};
        std::vector<std::vector<int>> result = levelOrderBottom(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
