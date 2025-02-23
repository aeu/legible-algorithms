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
    bool left_side = compareTrees( left->left, right->left );
    bool right_side = compareTrees( left->right, right->right );


    return ( left_side && right_side );
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
    return compareTrees(p,q);
}


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

int main(int argc, char **argv)
{
    std::cout << "Leetcode #100 - Same Tree" << std::endl;
    {
        std::vector<std::optional<int>> p = { 10,5,15 };
        std::vector<std::optional<int>> q = { 10,5,std::nullopt,std::nullopt,15 };
        std::cout << "Input p : " ;
        dumpValues( p );
        std::cout << "Input q : " ;
        dumpValues( q );
        TreeNode *p_tree = buildTree(p);
        TreeNode *q_tree = buildTree(q);
        bool same = isSameTree(p_tree,q_tree);
        std::cout << "They" << ( same ? " are " : " are not " ) << "the same" << std::endl;
    }
    {
        //        std::vector<std::optional<int>> p = { 10,5,15 };
        std::vector<std::optional<int>> p = { 10,5,std::nullopt,std::nullopt,15 };
        std::vector<std::optional<int>> q = { 10,5,std::nullopt,std::nullopt,15 };
        std::cout << "Input p : " ;
        dumpValues( p );
        std::cout << "Input q : " ;
        dumpValues( q );
        TreeNode *p_tree = buildTree(p);
        TreeNode *q_tree = buildTree(q);
        bool same = isSameTree(p_tree,q_tree);
        std::cout << "They" << ( same ? " are " : " are not " ) << "the same" << std::endl;
    }
    return -1;
    {
        std::vector<std::optional<int>> p = { 1,2,3 };
        std::vector<std::optional<int>> q = { 1,2,3 };
        std::cout << "Input p : " ;
        dumpValues( p );
        std::cout << "Input q : " ;
        dumpValues( q );
        TreeNode *p_tree = buildTree(p);
        TreeNode *q_tree = buildTree(q);
        bool same = isSameTree(p_tree,q_tree);
        std::cout << "They" << ( same ? " are " : " are not " ) << "the same" << std::endl;
    }
    {
        std::vector<std::optional<int>> p = { 1,2 };
        std::vector<std::optional<int>> q = { 1,std::nullopt,2 };
        std::cout << "Input p : " ;
        dumpValues( p );
        std::cout << "Input q : " ;
        dumpValues( q );
        TreeNode *p_tree = buildTree(p);
        TreeNode *q_tree = buildTree(q);
        bool same = isSameTree(p_tree,q_tree);
        std::cout << "They" << ( same ? " are " : " are not " ) << "the same" << std::endl;
    }
    {
        std::vector<std::optional<int>> p = { 1,2,1 };
        std::vector<std::optional<int>> q = { 1,1,2 };
        std::cout << "Input p : " ;
        dumpValues( p );
        std::cout << "Input q : " ;
        dumpValues( q );
        TreeNode *p_tree = buildTree(p);
        TreeNode *q_tree = buildTree(q);
        bool same = isSameTree(p_tree,q_tree);
        std::cout << "They" << ( same ? " are " : " are not " ) << "the same" << std::endl;
    }
    {
    }
    return -1;
}
