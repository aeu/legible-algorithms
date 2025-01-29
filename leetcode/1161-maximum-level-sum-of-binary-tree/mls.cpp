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
#include "TreeNode.h"


void dumpValues(const std::vector<std::optional<int>> &values )
{
    bool first_time = true;
    std::cout << "[";
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        if( current.has_value() )
            std::cout << current.value();
        else
            std::cout << "null";
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


std::shared_ptr<TreeNode> buildTree(std::vector<std::optional<int>> values)
{
    if( values.empty() )
        return nullptr;
    std::queue<std::shared_ptr<TreeNode>> node_queue;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>( values[0].value() );
    node_queue.push(root);
    size_t index=1;
    while(index < values.size())
    {
        std::shared_ptr<TreeNode> current = node_queue.front();
        node_queue.pop();
        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>( values[index].value() );
            current->setLeft(left);
            node_queue.push(left);
        }
        index++;
        if( ( index < values.size() ) && ( values[index].has_value() ) )
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>( values[index].value() );
            current->setRight(right);
            node_queue.push(right);
        }
        index++;
    }
    return root;    
}

struct NodeAndLevel
{
    std::shared_ptr<TreeNode> node;
    int level;
};

int maxLevelSum(std::shared_ptr<TreeNode> root)
{
    std::map<int,int> sums_for_levels;
    std::queue<NodeAndLevel> node_queue;
    NodeAndLevel current;
    current.node = root;
    current.level = 1;
    node_queue.push(current);
    while( ! node_queue.empty() )
    {
        current = node_queue.front();
        node_queue.pop();
        sums_for_levels[current.level] += current.node->getValue();
        if( current.node->getLeft() != nullptr )
        {
            NodeAndLevel left;
            left.node = current.node->getLeft();
            left.level = current.level + 1;
            node_queue.push( left );
        }
        if( current.node->getRight() != nullptr )
        {
            NodeAndLevel right;
            right.node = current.node->getRight();
            right.level = current.level + 1;
            node_queue.push( right );
        }
    }
    int max_level = 0;
    int max_value = 0;
    for(auto current : sums_for_levels )
    {
        if( current.second > max_value )
        {
            max_value = current.second;
            max_level = current.first;
        }
    }
    std::cout << "max level : " << max_level << std::endl;
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1161 - Maximum Level Sum of a Binary Tree" << std::endl;
    {
        std::vector<std::optional<int>> values = { 1,7,0,7,-8,std::nullopt,std::nullopt };
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        maxLevelSum( root );
    }
    {
        std::vector<std::optional<int>> values = { 989,std::nullopt,10250,98693,-89388,std::nullopt,std::nullopt,std::nullopt,-32127};
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        maxLevelSum( root );
    }

    return -1;
}
