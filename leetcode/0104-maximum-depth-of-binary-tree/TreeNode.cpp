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
