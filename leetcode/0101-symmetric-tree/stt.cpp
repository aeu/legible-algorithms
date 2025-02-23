// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>


void dumpValues(const std::vector<std::optional<int>> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(auto current : values )
    {
        if( first_time == false )
            std::cout << ", " ;

        if( current.has_value() )
            std::cout << current.value();
        else
            std::cout << "null";
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<std::optional<int>> values)
{
    if( values.empty() )
        return nullptr;
    
    TreeNode *root = new TreeNode(values[0].value());
    int index=1;
    std::queue<TreeNode *> nodes;
    nodes.push(root);
    while( index < values.size() )
    {
        TreeNode *curr = nodes.front();
        nodes.pop();
        if( values[index].has_value() )
        {
            TreeNode *new_left = new TreeNode(values[index].value());
            curr->left = new_left;
            nodes.push(new_left);
        }
        index++;
        if(( index < values.size()) && ( values[index].has_value() ))
        {
            TreeNode *new_right = new TreeNode(values[index].value());
            curr->right = new_right;
            nodes.push(new_right);
        }
        index++;
    }
    return root;
}


bool compareTrees(TreeNode *left, TreeNode *right)
{
    if(( left == nullptr ) && ( right == nullptr ))
    {
        return true;
    }
    
    if(( left == nullptr ) || ( right == nullptr ))
    {
        return false;
    }

    if(( left->val ) != ( right->val ) )
    {
        return false;
    }
    bool left_side = compareTrees( left->left, right->right );
    bool right_side = compareTrees( left->right, right->left );


    return ( left_side && right_side );
}

 bool isSymmetric(TreeNode* root)
 {
     return compareTrees( root->left, root->right );
 }



int main(int argc, char **argv)
{
    std::cout << "Leetcode #101 - Symmetric Tree" << std::endl;
    {
        std::vector<std::optional<int>> p = {1,2,2,3,4,4,3};
        TreeNode *p_tree = buildTree(p);
        bool symmetric = isSymmetric(p_tree);
        std::cout << "They" << ( symmetric ? " are " : " are not " ) << "symmetric" << std::endl;
    }
    {
        std::vector<std::optional<int>> p = {1,2,2,std::nullopt,3,std::nullopt,3};
        TreeNode *p_tree = buildTree(p);
        bool symmetric = isSymmetric(p_tree);
        std::cout << "They" << ( symmetric ? " are " : " are not " ) << "symmetric" << std::endl;
    }
    return -1;
}
