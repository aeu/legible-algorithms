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


std::shared_ptr<TreeNode> buildTree(const std::vector<std::optional<int>> &values )
{
    if( values.empty() )
        return nullptr;
    size_t index = 0;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(values[index].value());
    std::queue<std::shared_ptr<TreeNode>> nodes;
    nodes.push(root);
    index++;
    while(index<values.size())
    {
        std::shared_ptr<TreeNode> current = nodes.front();
        nodes.pop();
        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>( values[index].value());
            current->setLeft(left);
            nodes.push(left);
        }
        index++;
        if((index<values.size()) && ( values[index].has_value() ))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>( values[index].value());
            current->setRight(right);
            nodes.push(right);
        }
        index++;
    }
    return root;
}

std::shared_ptr<TreeNode> searchBST(std::shared_ptr<TreeNode> root,
                                    int val)
{
    if( root == nullptr )
        return nullptr;

    if( root->getValue() == val )
        return root;

    if( val < root->getValue() )
        return searchBST( root->getLeft(),val);
    
    return searchBST(root->getRight(),val);
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #700 - Search in a Binary Search Tree" << std::endl;
    {
        int seek_value = 2;
        std::vector<std::optional<int>> values = { 4,2,7,1,3};
        std::cout << "Searching for : " << seek_value << " in : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        std::shared_ptr<TreeNode> found_root = searchBST(root,seek_value);
        std::cout << "Found Tree : ";
        TreeNode::dumpTree(found_root);
    }
    {
        int seek_value = 5;
        std::vector<std::optional<int>> values = { 4,2,7,1,3};
        std::cout << "Searching for : " << seek_value << " in : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        std::shared_ptr<TreeNode> found_root = searchBST(root,seek_value);
        std::cout << "Found Tree : ";
        TreeNode::dumpTree(found_root);
    }
    return -1;
}
