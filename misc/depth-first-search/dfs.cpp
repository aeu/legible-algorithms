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

    std::shared_ptr<TreeNode> root;
    std::queue<std::shared_ptr<TreeNode>> nodes;
    int index = 0;
    if( values[index].has_value() )
    {
        root = std::make_shared<TreeNode>(values[index].value());
        nodes.push(root);
    }
    index++;
    std::shared_ptr<TreeNode> current;
    while( index < values.size() )
    {
        current = nodes.front();
        nodes.pop();
        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>(values[index].value() );
            current->setLeft(left);
            nodes.push(left);
        }
        index++;
        if(( index < values.size()) && ( values[index].has_value() ))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(values[index].value() );
            current->setRight(right);
            nodes.push(right);
        }
        index++;
    }
    return root;
}


bool depthFirstSearch(std::shared_ptr<TreeNode> current_node,
                      std::vector<std::optional<int>> &path,
                      const int &target )
{
    if( current_node == nullptr )
        return false;

    path.push_back( current_node->getValue() );

    if( current_node->getValue() == target )
        return true;

    if( ( depthFirstSearch( current_node->getLeft(), path, target ) )
        || ( depthFirstSearch( current_node->getRight(), path, target )))
    {
        return true;
    }
    path.pop_back();
    return false;
}

std::vector<std::optional<int>> findPath(std::shared_ptr<TreeNode> current_node,
                                         const int &target )
{
    std::vector<std::optional<int>> path;
    bool did_find_path = depthFirstSearch(current_node, path, target);
    if( did_find_path )
        dumpValues( path );
    return path;
}


int main(int argc, char **argv)
{
    {
        std::vector<std::optional<int>> values = { 3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        findPath(root,4);
    }
    return -1;
}
