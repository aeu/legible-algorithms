// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <memory>
#include "TreeNode.h"


TreeNode::NodeColour TreeNode::getColour()
{
    return NodeColour::RED;
}

TreeNode::NodeColour TreeNode::setColour(TreeNode::NodeColour new_colour)
{
    colour = new_colour;
    return colour;
}

int TreeNode::getValue()
{
    return value;
}

std::shared_ptr<TreeNode> TreeNode::getLeft()
{
    return left;
}

std::shared_ptr<TreeNode> TreeNode::getRight()
{
    return right;
}

std::shared_ptr<TreeNode> TreeNode::getParent()
{
    return parent;
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

std::shared_ptr<TreeNode> TreeNode::setParent(std::shared_ptr<TreeNode> new_parent)
{
    parent = new_parent;
    return parent;
}

int TreeNode::setValue(int new_value)
{
    value = new_value;
    return value;
}


TreeNode::TreeNode(int new_value)
{
    value = new_value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    colour = RED;
}
