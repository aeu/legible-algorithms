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

#if 0
void dumpValues(const std::vector<int> values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}
#endif    


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

void buildLeafList(std::shared_ptr<TreeNode> current_node,
                   std::vector<std::optional<int>> &leaf_list)
{
    if( current_node != nullptr )
    {
        buildLeafList(current_node->getLeft(), leaf_list);
        if(( current_node->getLeft() == nullptr )  && ( current_node->getRight() == nullptr ))
        {
            leaf_list.push_back( current_node->getValue());
        }
        buildLeafList(current_node->getRight(), leaf_list);
    }
}


std::vector<std::optional<int>> leafList(std::shared_ptr<TreeNode> root)
{
    std::vector<std::optional<int>> leaves;
    buildLeafList(root, leaves);
    return leaves;
}


bool leafSimilar(std::shared_ptr<TreeNode> root1,
                 std::shared_ptr<TreeNode> root2)
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

        std::cout << "Input 1 : " ;
        dumpValues( values_1 );
        
        std::cout << "Input 2 : " ;
        dumpValues( values_2 );
        
        std::shared_ptr<TreeNode> root1 = TreeNode::buildTree(values_1);
        std::shared_ptr<TreeNode> root2 = TreeNode::buildTree(values_2);

        bool are_similar = leafSimilar(root1, root2);
        std::cout << "Are similar: " << ( are_similar ? "true" : "false" ) << std::endl;
    }
    {
        std::vector<std::optional<int>> values_1 = {1,2,3};
        std::vector<std::optional<int>> values_2 = {1,3,2};
        
        std::cout << "Input 1 : " ;
        dumpValues( values_1 );
        
        std::cout << "Input 2 : " ;
        dumpValues( values_2 );
        
        std::shared_ptr<TreeNode> root1 = TreeNode::buildTree(values_1);
        std::shared_ptr<TreeNode> root2 = TreeNode::buildTree(values_2);

        bool are_similar = leafSimilar(root1, root2);
        std::cout << "Are similar: " << ( are_similar ? "true" : "false" ) << std::endl;
    }
    return -1;
}
