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
#include "TreeNode.h"



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

void dumpNode(std::shared_ptr<TreeNode> current_node )
{
    if( current_node != nullptr )
    {
        std::cout << current_node->getValue() << " " ;
        dumpNode( current_node->getLeft());
        dumpNode( current_node->getRight());
    }
}

int maxDepth(std::shared_ptr<TreeNode> current)
{
    int left_depth = 0;
    int right_depth = 0;
    if( current != nullptr )
    {
        left_depth = maxDepth( current->getLeft() );
        right_depth = maxDepth( current->getRight() );
        return 1 + std::max(left_depth, right_depth);
    }
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #104 - Maximum Depth of Binary Tree" << std::endl;
    {
        std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
        std::cout << "Input : " ;
        dumpValues( values );
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        int max_depth = maxDepth( root );
        std::cout << "Max depth : " << max_depth << std::endl;
    }
    {
        std::vector<std::optional<int>> values = { 1,std::nullopt,2 };
        std::cout << "Input : " ;
        dumpValues( values );
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        int max_depth = maxDepth( root );
        std::cout << "Max depth : " << max_depth << std::endl;
    }
    return -1;
}
