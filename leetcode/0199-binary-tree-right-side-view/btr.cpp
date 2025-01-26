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
    size_t index = 0;
    std::queue<std::shared_ptr<TreeNode>> nodes;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>( values[index].value() );
    nodes.push(root);
    
    index++;
    while(index < values.size() )
    {
        std::shared_ptr<TreeNode> current = nodes.front();
        nodes.pop();

        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>( values[index].value() );
            current->setLeft(left);
            nodes.push(left);
        }
        index++;
        if( index < values.size() && values[index].has_value())
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>( values[index].value() );
            current->setRight(right);
            nodes.push(right);
        }
        index++;
    }
    return root;
    
}

struct NodeAndLevel {
    std::shared_ptr<TreeNode> node;
    int level;
};


void breadthFirstSearch(std::queue<NodeAndLevel> node_list,
                  std::vector<NodeAndLevel> &processed,
                  int level )
{
    NodeAndLevel current;
    while( ! node_list.empty() )
    {
        current = node_list.front();
        node_list.pop();
        processed.push_back(current);
        if( current.node->getLeft() != nullptr )
        {
            NodeAndLevel left;
            left.node = current.node->getLeft();
            left.level = current.level+1;
            node_list.push(left);
        }
        if( current.node->getRight() != nullptr )
        {
            NodeAndLevel right;
            right.node = current.node->getRight();
            right.level = current.level+1;
            node_list.push(right);
        }
    }
}


std::vector<std::optional<int>> breadthFirstTraversal(std::shared_ptr<TreeNode> root )
{
    std::vector<std::optional<int>> values;
    if( root != nullptr )
    {
        std::queue<NodeAndLevel> node_list;
        std::vector<NodeAndLevel> processed;
        NodeAndLevel current;
        current.node = root;
        current.level = 0;
        node_list.push(current);
        breadthFirstSearch(node_list,processed,0);
        int last_level = 0;
        NodeAndLevel previous;
        for(size_t index=0;index<processed.size();index++)
        {
            current = processed[index];
            if( current.level != last_level )
            {
                previous = processed[index-1];
                values.push_back( previous.node->getValue());
                last_level = current.level;
            }
        }
        // the last node is always going to linger because there is no
        // next level
        values.push_back((processed.back().node->getValue()));
    }
    return values;   
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #199 - Binary Tree Right Side View" << std::endl;
    {
        std::vector<std::optional<int>> values = { 1,2,3,std::nullopt,5,std::nullopt,4 };
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        std::vector<std::optional<int>> right_sides = breadthFirstTraversal(root);
        std::cout << "Right Side View : ";
        dumpValues( right_sides );
    }
    {
        std::vector<std::optional<int>> values = { 1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5 };
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        std::vector<std::optional<int>> right_sides = breadthFirstTraversal(root);
        std::cout << "Right Side View : ";
        dumpValues( right_sides );
    }
    {
        std::vector<std::optional<int>> values = { 1,std::nullopt,3};
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        std::vector<std::optional<int>> right_sides = breadthFirstTraversal(root);
        std::cout << "Right Side View : ";
        dumpValues( right_sides );
    }
    {
        std::vector<std::optional<int>> values = {};
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        std::vector<std::optional<int>> right_sides = breadthFirstTraversal(root);
        std::cout << "Right Side View : ";
        dumpValues( right_sides );
    }

    return -1;
}
