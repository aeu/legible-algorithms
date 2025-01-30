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

std::shared_ptr<TreeNode> buildTree(const std::vector<std::optional<int>> &values)
{
    if( values.empty() )
        return nullptr;
    
    size_t index = 0;
    std::queue<std::shared_ptr<TreeNode>> node_queue;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(values[index].value());
    node_queue.push( root );
    index++;
    while( index < values.size() )
    {
        std::shared_ptr<TreeNode> current = node_queue.front();
        node_queue.pop();
        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>(values[index].value());
            current->setLeft(left);
            node_queue.push(left);
        }
        index++;
        if((index<values.size()) && ( values[index].has_value() ))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(values[index].value());
            current->setRight(right);
            node_queue.push(right);
        }
        index++;
    }
    return root;
}


void replaceChild(std::shared_ptr<TreeNode> parent,
                  std::shared_ptr<TreeNode> old_child,
                  std::shared_ptr<TreeNode> new_child)
{
    if( parent->getLeft() == old_child )
        parent->setLeft( new_child );
    else
        parent->setRight( new_child );
}

void findAndDelete(std::shared_ptr<TreeNode> parent,
                   std::shared_ptr<TreeNode> candidate,
                   const int key)
{
    if( candidate == nullptr )
        return;
    if( candidate->getValue() == key )
    {
        if(( candidate->getLeft() == nullptr ) && ( candidate->getRight() == nullptr ))
        {
            replaceChild(parent,candidate,nullptr);
        }
        else if( candidate->getLeft() == nullptr )
        {
            replaceChild(parent,candidate,candidate->getRight());
        }
        else
        {
            replaceChild(parent,candidate,candidate->getLeft());
        }
    }
    else if( candidate->getValue() < key )
        findAndDelete( candidate, candidate->getRight(), key );
    else
        findAndDelete( candidate, candidate->getLeft(), key );
}

std::shared_ptr<TreeNode> deleteNode(std::shared_ptr<TreeNode> root,
                                     int key)
{
    if( root == nullptr )
        return nullptr;

    if( root->getValue() == key )
    {
        if( root->getLeft() == nullptr )
            return root->getRight();
        if( root->getRight() == nullptr )
            return root->getLeft();
    }
    else if( root->getValue() < key )
        findAndDelete(root,root->getRight(),key);
    else
        findAndDelete(root,root->getLeft(),key);

    return root;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #450 - Delete Node in a BST" << std::endl;
    {
        int deletion = 3;
        std::vector<std::optional<int>> values = {5,3,6,2,4,std::nullopt,7};
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        std::cout << "About to try to delete : " << deletion << std::endl;
        deleteNode(root, deletion);
        TreeNode::dumpTree( root );
    }
    return 0;
    {
        int deletion = 0;
        std::vector<std::optional<int>> values = {5,3,6,2,4,std::nullopt,7};
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        TreeNode::dumpTree( root );
        std::cout << "About to try to delete : " << deletion << std::endl;
        deleteNode(root, deletion);
        TreeNode::dumpTree( root );
    }
    return -1;
}
