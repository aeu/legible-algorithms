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
    int index = 0;
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

void bfs(std::queue<NodeAndLevel> node_list,
         std::vector<NodeAndLevel> &processed,
         int level )
{
    if( node_list.empty() )
        return;

    level++;
    NodeAndLevel current = node_list.front();
    node_list.pop();

    processed.push_back( current );
    
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
    bfs( node_list, processed, level );
}


void breadthFirstTraversal(std::shared_ptr<TreeNode> root )
{
    std::vector<std::optional<int>> values;
    if( root == nullptr )
    {
        std::cout << "nullroot" << std::endl;
        dumpValues( values );
    }
    std::queue<NodeAndLevel> node_list;
    std::vector<NodeAndLevel> processed;
    NodeAndLevel current;
    current.node = root;
    current.level = 0;
    node_list.push(current);
    bfs(node_list,processed,0);
    int last_level = 0;
    NodeAndLevel previous;
    for(int index=0;index<processed.size();index++)
    {
        // if( index == 0 )
        // {
        //     values.push_back( current.node->getValue());
        // }
        current = processed[index];
        if( current.level != last_level )
        {
            previous = processed[index-1];
            values.push_back( previous.node->getValue());
            last_level = current.level;
        }
    }
    values.push_back( ( processed.back().node->getValue()));
    dumpValues( values );
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #199 - Binary Tree Right Side View" << std::endl;
    {
        std::vector<std::optional<int>> values = { 1,2,3,std::nullopt,5,std::nullopt,4 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        breadthFirstTraversal(root);
    }
    {
        std::vector<std::optional<int>> values = { 1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        breadthFirstTraversal(root);
    }
    {
        std::vector<std::optional<int>> values = { 1,std::nullopt,3};
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        breadthFirstTraversal(root);
    }
    {
        std::vector<std::optional<int>> values = {};
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        breadthFirstTraversal(root);
    }

    return -1;
}
