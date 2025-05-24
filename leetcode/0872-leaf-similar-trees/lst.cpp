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



void buildLeafList(TreeNode * current_node,
                   std::vector<std::optional<int>> &leaf_list)
{
    if( current_node != nullptr )
    {
        buildLeafList(current_node->left, leaf_list);
        if(( current_node->left == nullptr )  && ( current_node->right == nullptr ))
        {
            leaf_list.push_back( current_node->val);
        }
        buildLeafList(current_node->right, leaf_list);
    }
}


std::vector<std::optional<int>> leafList(TreeNode * root)
{
    std::vector<std::optional<int>> leaves;
    buildLeafList(root, leaves);
    return leaves;
}


bool leafSimilar(TreeNode * root1,
                 TreeNode * root2)
{
    std::vector<std::optional<int>> leaves1 = leafList(root1);
    std::vector<std::optional<int>> leaves2 = leafList(root2);
    if( leaves1 == leaves2 )
        return true;
    return false;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #872 - Leaf Similar Trees" << std::endl;
    {
        std::vector<std::optional<int>> values_1 = {3,5,1,6,2,9,8,std::nullopt,std::nullopt,7,4};
        std::vector<std::optional<int>> values_2 =
            {3,5,1,6,7,4,2,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,9,8};

        TreeNode * root1 = buildTree(values_1);
        TreeNode * root2 = buildTree(values_2);

        bool are_similar = leafSimilar(root1, root2);
        std::cout << "Are similar: " << ( are_similar ? "true" : "false" ) << std::endl;
    }
    {
        std::vector<std::optional<int>> values_1 = {1,2,3};
        std::vector<std::optional<int>> values_2 = {1,3,2};
        
        TreeNode * root1 = buildTree(values_1);
        TreeNode * root2 = buildTree(values_2);

        bool are_similar = leafSimilar(root1, root2);
        std::cout << "Are similar: " << ( are_similar ? "true" : "false" ) << std::endl;
    }
    return -1;
}
