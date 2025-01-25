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

void dumpTree(std::shared_ptr<TreeNode> current_node )
{
    std::cout << "[";
    dumpNode(current_node);
    std::cout << "]" << std::endl;
}


std::shared_ptr<TreeNode> buildTree(const std::vector<std::optional<int>> &values)
{
    if( values.empty() )
        return nullptr;

    std::shared_ptr<TreeNode> root_node;
    std::queue<std::shared_ptr<TreeNode>> node_queue;
    if( values[0].has_value() )
    {
        root_node = std::make_shared<TreeNode>(values[0].value());
        node_queue.push( root_node );
    }

    int index = 1;
    while( index < values.size () )
    {
        std::shared_ptr<TreeNode> current = node_queue.front();
        node_queue.pop();

        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left_node = std::make_shared<TreeNode>(values[index].value());
            current->setLeft(left_node);
            node_queue.push(left_node);
        }
        index++;
        if((index < values.size()) && ( values[index].has_value() ))
        {
            std::shared_ptr<TreeNode> right_node = std::make_shared<TreeNode>(values[index].value());
            current->setRight(right_node);
            node_queue.push(right_node);
        }
        index++;
    }
    return root_node;
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
    {
        std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        dumpTree( root );
        int max_depth = maxDepth( root );
        std::cout << "Max depth : " << max_depth << std::endl;
    }
    {
        std::vector<std::optional<int>> values = { 1,std::nullopt,2 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        dumpTree( root );
        int max_depth = maxDepth( root );
        std::cout << "Max depth : " << max_depth << std::endl;
    }
    return -1;
}
