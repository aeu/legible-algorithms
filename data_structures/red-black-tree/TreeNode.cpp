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
    printf("Setting the left of %d to %d\n", value, new_left->getValue() );
    left = new_left;
    return left;
}

std::shared_ptr<TreeNode> TreeNode::setRight(std::shared_ptr<TreeNode> new_right)
{
    printf("Setting the right of %d to %d\n", value, new_right->getValue() );
    right = new_right;
    return right;
}

std::shared_ptr<TreeNode> TreeNode::setParent(std::shared_ptr<TreeNode> new_parent)
{
    parent = new_parent;
    return parent;
}

TreeNode::TreeNode(int new_value)
{
    value = new_value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    colour = RED;
}
