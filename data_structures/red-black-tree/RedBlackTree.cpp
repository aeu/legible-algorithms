// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include "RedBlackTree.h"
#include "TreeNode.h"
#include <stdio.h>
#include <memory>

RedBlackTree::RedBlackTree()
{
    int nil_value = -1;
    this->nilnode = std::make_shared<TreeNode>(nil_value);
    this->root_node = nilNode();
    printf("Created an empty red black tree\n");
}

std::shared_ptr<TreeNode> RedBlackTree::addValue(int new_value)
{
    std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>(new_value);
    insert(new_node);
    return new_node;
}

std::shared_ptr<TreeNode> RedBlackTree::find(int value)
{
    return find(this->root_node, value );
}

std::shared_ptr<TreeNode> RedBlackTree::find(std::shared_ptr<TreeNode> start_node,
                                             int value)
{
    if( start_node == nullptr )
        return nilNode();

    if( start_node->getValue() == value )
    {
        return start_node;
    }

    if( value < start_node->getValue() )
        return find ( start_node->getLeft(), value );
    else
        return find ( start_node->getRight(), value );

    return nilNode();
}


void RedBlackTree::inOrderTreeWalk(std::shared_ptr<TreeNode> start_node)
{
    if( start_node != nullptr )
    {
        inOrderTreeWalk( start_node->getLeft() );
        printf("%d, ", start_node->getValue());
        inOrderTreeWalk( start_node->getRight());
    }
}

void RedBlackTree::leftRotate(std::shared_ptr<TreeNode> start_node)
{
}

void RedBlackTree::rightRotate(std::shared_ptr<TreeNode> start_node)
{
}


std::shared_ptr<TreeNode> RedBlackTree::maximum(std::shared_ptr<TreeNode> start_node)
{
    std::shared_ptr<TreeNode> maximum = start_node;
    if( maximum == nullptr )
        maximum = root_node;
    while( maximum != nullptr && maximum->getRight() != nullptr )
    {
        maximum = maximum->getRight();
    }
    return maximum;
}

std::shared_ptr<TreeNode> RedBlackTree::minimum(std::shared_ptr<TreeNode> start_node)
{
    std::shared_ptr<TreeNode> minimum = start_node;
    if( minimum == nullptr )
        minimum = root_node;
    while( minimum != nullptr && minimum->getLeft() != nullptr )
    {
        minimum = minimum->getLeft();
    }
    return minimum;
}

std::shared_ptr<TreeNode> RedBlackTree::nilNode()
{
    return nilnode;
}


std::shared_ptr<TreeNode> RedBlackTree::predecessor(std::shared_ptr<TreeNode> start_node)
{
    if( start_node->getLeft() != nullptr )
        return maximum(start_node->getLeft());

    std::shared_ptr<TreeNode> predecessor = start_node->getParent();
    std::shared_ptr<TreeNode> temp_node = start_node;

    while( predecessor != nullptr && temp_node == predecessor->getLeft() )
    {
        temp_node = predecessor;
        predecessor = predecessor->getParent();
    }
    return predecessor;
}

std::shared_ptr<TreeNode> RedBlackTree::remove(int value)
{
    printf("\ntrying to remove %d\n", value );
    std::shared_ptr<TreeNode> removed = find(value);
    if( removed == nullptr )
        return nullptr;

    // case 1, node being removed has no children

    if(( removed->getLeft() == nullptr ) && ( removed->getRight() == nullptr ))
    {
        if( removed->getParent()->getLeft() == removed )
            removed->getParent()->setLeft(nullptr);
        else
            removed->getParent()->setRight(nullptr);
        return removed;
    }

    // case 2, node being remove has one child

    if(( removed->getLeft() == nullptr ) || ( removed->getRight() == nullptr ))
    {
        std::shared_ptr<TreeNode> child = removed->getLeft();
        if( child != nullptr )
        {
            child->setParent( removed->getParent () );
        }
        else
        {
            child = removed->getRight();
            child->setParent( removed->getParent() );
        }
        if( removed->getParent()->getLeft() == removed )
            removed->getParent()->setLeft(child);
        else
            removed->getParent()->setRight(child);
        return removed;
    }

    // case 3, node being removed has two children
    std::shared_ptr<TreeNode> left_child = removed->getLeft();
    std::shared_ptr<TreeNode> right_child = removed->getRight();
    if(( left_child != nullptr ) && ( right_child != nullptr ))
    {
        std::shared_ptr<TreeNode> successor_node = this->successor(removed);
        if( successor_node != nullptr )
        {
            removed->setValue( successor_node->getValue());
            if( successor_node->getParent()->getLeft() == successor_node )
                successor_node->getParent()->setLeft(nullptr);
            else
                successor_node->getParent()->setRight(nullptr);
            return successor_node;
        }
    }
    return nullptr;
}

std::shared_ptr<TreeNode> RedBlackTree::successor(std::shared_ptr<TreeNode> start_node)
{
    if( start_node->getRight() != nullptr )
        return minimum(start_node->getRight());

    std::shared_ptr<TreeNode> temp_node = start_node;
    std::shared_ptr<TreeNode> successor = start_node->getParent();

    while( successor != nullptr && temp_node == successor->getRight() )
    {
        temp_node = successor;
        successor = successor->getParent();
    }
    return successor;
}


std::shared_ptr<TreeNode> RedBlackTree::insert(std::shared_ptr<TreeNode> new_node)
{
    std::shared_ptr<TreeNode> temp_node = nilNode();
    std::shared_ptr<TreeNode> insertion_parent = this->root_node;
    new_node->setLeft(nilNode());
    new_node->setRight(nilNode());
    new_node->setParent(nilNode());
    while( insertion_parent != nullptr )
    {
        temp_node = insertion_parent;
        if( new_node->getValue() < insertion_parent->getValue() )
            insertion_parent = insertion_parent->getLeft();
        else
            insertion_parent = insertion_parent->getRight();
    }
    new_node->setParent(temp_node);
    if( temp_node == nilNode() )
    {
        printf("Tree was empty, setting the root to %d\n", new_node->getValue());
        root_node = new_node;
    }
    else
    {
        if( new_node->getValue() < temp_node->getValue() )
            temp_node->setLeft( new_node );
        else
            temp_node->setRight( new_node );
    }
    return new_node;
}
