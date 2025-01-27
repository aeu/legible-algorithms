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

int nodeSearch(std::shared_ptr<TreeNode> current,
               const int base_value)
{
    if( current == nullptr )
        return 0;
    int max_value = base_value;
    int good = 0;
    if( current->getValue() >= max_value )
        good = 1;

    max_value = std::max( max_value, current->getValue());

    good += nodeSearch( current->getLeft(), max_value );
    good += nodeSearch( current->getRight(), max_value );

    return good;
}



int countGoodNodes(std::shared_ptr<TreeNode> current)
{
    int good_nodes = nodeSearch(current, current->getValue());
    return good_nodes;
}
                  

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1448 - Count Good Nodes in Binary Tree" << std::endl;
    {
        std::vector<std::optional<int>> values = {3,1,4,3,std::nullopt,1,5};

        std::cout << "Input : " ;
        dumpValues( values );
        
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        int good_node_count = countGoodNodes(root);
        std::cout << "good node count : " << good_node_count << std::endl;
    }
    {
        std::vector<std::optional<int>> values = {3,3,std::nullopt,4,2};

        std::cout << "Input : " ;
        dumpValues( values );
        
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        int good_node_count = countGoodNodes(root);
        std::cout << "good node count : " << good_node_count << std::endl;
    }
    {
        std::vector<std::optional<int>> values = {1};
        
        std::cout << "Input : " ;
        dumpValues( values );
        
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        int good_node_count = countGoodNodes(root);
        std::cout << "good node count : " << good_node_count << std::endl;
    }
    return -1;
}
