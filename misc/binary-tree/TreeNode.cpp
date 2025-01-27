// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include "TreeNode.h"

TreeNode::TreeNode()
{
    setValue(0);
    setLeft(nullptr);
    setRight(nullptr);
}

TreeNode::TreeNode(const int new_value)
{
    setValue(new_value);
    setLeft(nullptr);
    setRight(nullptr);
}

TreeNode::TreeNode(const int new_value,
                   std::shared_ptr<TreeNode> new_left,
                   std::shared_ptr<TreeNode> new_right)
{
    setValue(new_value);
    setLeft(new_left);
    setRight(new_right);
}


std::shared_ptr<TreeNode> TreeNode::getLeft()
{
    return left;
}

std::shared_ptr<TreeNode> TreeNode::getRight()
{
    return right;
}

std::shared_ptr<TreeNode> TreeNode::setLeft(std::shared_ptr<TreeNode> new_left)
{
    left = new_left;
    return left;
}
 
std::shared_ptr<TreeNode> TreeNode::setRight(std::shared_ptr<TreeNode> new_right)
{
    right = new_right;
    return right;
}

void TreeNode::setValue(const int new_value)
{
    value = new_value;
}

int TreeNode::getValue()
{
    return value;
}


void TreeNode::dumpNode(std::shared_ptr<TreeNode> current_node )
{
    if( current_node != nullptr )
    {
        std::cout << current_node->getValue() << " " ;
        TreeNode::dumpNode( current_node->getLeft());
        TreeNode::dumpNode( current_node->getRight());
    }
}

void TreeNode::dumpTree(std::shared_ptr<TreeNode> current_node )
{
    std::cout << "[";
    TreeNode::dumpNode(current_node);
    std::cout << "]" << std::endl;
}


std::shared_ptr<TreeNode> TreeNode::buildTree(const std::vector<std::optional<int>> &values)
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
