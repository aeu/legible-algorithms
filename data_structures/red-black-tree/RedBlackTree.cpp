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
    int nil_value = -1337;
    this->nilnode = std::make_shared<TreeNode>(nil_value);
    this->nilnode->setColour(TreeNode::NodeColour::BLACK);
    this->root_node = nilNode();
    debug_out = true;
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
    if( start_node == nilNode() )
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


void RedBlackTree::dumpDotLine(FILE *fp, std::shared_ptr<TreeNode> start_node)
{
    if( start_node != nilNode() )
    {
        dumpDotLine(fp, start_node->getLeft() );
        if( start_node->getLeft() != nilNode() )
        {
            fprintf(fp, "\t%d -> %d;\n", start_node->getValue(), start_node->getLeft()->getValue());
        }
        if( start_node->getRight() != nilNode() )
        {
            fprintf(fp, "\t%d -> %d;\n", start_node->getValue(), start_node->getRight()->getValue());
        }
        if( start_node->getColour() == TreeNode::NodeColour::RED )
        {
             fprintf(fp, "\t%d [fillcolor=red];\n", start_node->getValue());
        }
        if( start_node->getColour() == TreeNode::NodeColour::BLACK )
        {
             fprintf(fp, "\t%d [fillcolor=grey43];\n", start_node->getValue());
        }
        dumpDotLine(fp, start_node->getRight() );
    }
}

void RedBlackTree::toDotFile(const char *filename, std::shared_ptr<TreeNode> start_node)
{
    FILE *fp = fopen(filename, "wt");
    if( fp )
    {
        fprintf(fp, "digraph G {\n");
        fprintf(fp, "\tnode [style=filled];\n");
        if( start_node == nilNode() )
            dumpDotLine(fp, root_node );
        else
            dumpDotLine(fp, start_node );
        fprintf(fp, "}\n");
    }
    printf("dot %s -Tpng > %s.png; open %s.png\n", filename, filename,filename );
}

void RedBlackTree::inOrderTreeWalk(std::shared_ptr<TreeNode> start_node)
{
    if( start_node != nilNode() )
    {
        inOrderTreeWalk( start_node->getLeft() );
        printf("%d, ", start_node->getValue());
        inOrderTreeWalk( start_node->getRight());
    }
}


void RedBlackTree::insertFixup(std::shared_ptr<TreeNode> z )
{
    std::shared_ptr<TreeNode> y = nilnode;
    std::shared_ptr<TreeNode> grandparent = nilnode;
    std::shared_ptr<TreeNode> parent = nilnode;
    std::shared_ptr<TreeNode> temp;
    int max = 0;
    while(( getParent(z) != nilnode ) &&
          ( getParent(z)->getColour() == TreeNode::NodeColour::RED ))
    {
        printf("1\n");
        grandparent = getGrandparent( z );
        if( grandparent == nilnode )
            break;

        if( getParent(z) == grandparent->getLeft() )
        {
            printf("2\n");
            y = grandparent->getRight();
            if(( y != nilnode ) && ( y->getColour() == TreeNode::NodeColour::RED ))
            {
                printf("3\n");
                getParent(z)->setColour( TreeNode::NodeColour::BLACK );
                y->setColour( TreeNode::NodeColour::BLACK );
                grandparent = getGrandparent(z);
                if( grandparent != nilnode )
                    grandparent->setColour( TreeNode::NodeColour::RED );
                z = grandparent;
            }
            else if( z == getParent(z)->getRight())
            {
                printf("4\n");
                z = getParent(z);
                leftRotate(z);
            }
            printf("5\n");
            getParent(z)->setColour( TreeNode::NodeColour::BLACK );
            grandparent = getGrandparent(z);
            if( grandparent != nilnode )
            {
                printf("6\n");
                grandparent->setColour(  TreeNode::NodeColour:: RED );
                rightRotate(grandparent);
            }
        }
        else if( getParent(z) == grandparent->getRight() )
        {
        }
    }
    this->root_node->setColour( TreeNode::NodeColour::BLACK );
}


/*
 * Rotations:
 *
 *               |                                      |
 *               y                                      x
 *              / \        <--- Left Rotate T,x        / \
 *             /   \       T,y  Right Rotate --->     /   \
 *            x     γ                                α     y
 *           / \                                          / \
 *          /   \                                        /   \
 *         α     β                                      β     γ
 *
 *
 */
std::shared_ptr<TreeNode> RedBlackTree::leftRotate(std::shared_ptr<TreeNode> x)
{
    std::shared_ptr<TreeNode> y = x->getRight();
    x->setRight( y->getLeft() );
    if( y->getLeft() != nilNode() )
    {
        y->getLeft()->setParent( x );
    }
    y->setParent( x->getParent() );
    if( x->getParent() == nilNode() )
    {
        root_node = y;
    }
    else if ( x == x->getParent()->getLeft() )
    {
        x->getParent()->setLeft( y );
    }
    else
    {
        x->getParent()->setRight( y );
    }
    y->setLeft( x );
    x->setParent( y );
    return y;
}

std::shared_ptr<TreeNode> RedBlackTree::rightRotate(std::shared_ptr<TreeNode> y)
{
    std::shared_ptr<TreeNode> x = y->getLeft();
    y->setLeft( x->getRight() );
    if( x->getRight() != nilNode() )
    {
        x->getRight()->setParent( y );
    }
    x->setParent( y->getParent() );
    if( y->getParent() == nilNode() )
    {
        root_node = x;
    }
    else if ( y == y->getParent()->getLeft() )
    {
        y->getParent()->setLeft( x );
    }
    else
    {
        y->getParent()->setRight( x );
    }
    x->setRight( y );
    y->setParent( x );
    return x;
}


std::shared_ptr<TreeNode> RedBlackTree::maximum(std::shared_ptr<TreeNode> start_node)
{
    std::shared_ptr<TreeNode> maximum = start_node;
    if( maximum == nilNode() )
        maximum = root_node;
    while( maximum != nilNode() && maximum->getRight() != nilNode() )
    {
        maximum = maximum->getRight();
    }
    return maximum;
}

std::shared_ptr<TreeNode> RedBlackTree::minimum(std::shared_ptr<TreeNode> start_node)
{
    std::shared_ptr<TreeNode> minimum = start_node;
    if( minimum == nilNode() )
        minimum = root_node;
    while( minimum != nilNode() && minimum->getLeft() != nilNode() )
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
    if( start_node->getLeft() != nilNode() )
        return maximum(start_node->getLeft());

    std::shared_ptr<TreeNode> predecessor = start_node->getParent();
    std::shared_ptr<TreeNode> temp_node = start_node;

    while( predecessor != nilNode() && temp_node == predecessor->getLeft() )
    {
        temp_node = predecessor;
        predecessor = predecessor->getParent();
    }
    return predecessor;
}

std::shared_ptr<TreeNode> RedBlackTree::getGrandparent(std::shared_ptr<TreeNode> node)
{
    std::shared_ptr<TreeNode> parent = node->getParent();
    if( parent == nilnode )
        return nilnode;

    std::shared_ptr<TreeNode> grandparent = parent->getParent();
    return grandparent;
}

std::shared_ptr<TreeNode> RedBlackTree::getParent(std::shared_ptr<TreeNode> node)
{
    return node->getParent();
}



std::shared_ptr<TreeNode> RedBlackTree::remove(int value)
{
    printf("\ntrying to remove %d\n", value );
    std::shared_ptr<TreeNode> removed = find(value);
    if( removed == nilNode() )
        return nilNode();

    // case 1, node being removed has no children

    if(( removed->getLeft() == nilNode() ) && ( removed->getRight() == nilNode() ))
    {
        if( removed->getParent()->getLeft() == removed )
            removed->getParent()->setLeft(nilNode());
        else
            removed->getParent()->setRight(nilNode());
        return removed;
    }

    // case 2, node being remove has one child

    if(( removed->getLeft() == nilNode() ) || ( removed->getRight() == nilNode() ))
    {
        std::shared_ptr<TreeNode> child = removed->getLeft();
        if( child != nilNode() )
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
    if(( left_child != nilNode() ) && ( right_child != nilNode() ))
    {
        std::shared_ptr<TreeNode> successor_node = this->successor(removed);
        if( successor_node != nilNode() )
        {
            removed->setValue( successor_node->getValue());
            if( successor_node->getParent()->getLeft() == successor_node )
                successor_node->getParent()->setLeft(nilNode());
            else
                successor_node->getParent()->setRight(nilNode());
            return successor_node;
        }
    }
    return nilNode();
}

std::shared_ptr<TreeNode> RedBlackTree::successor(std::shared_ptr<TreeNode> start_node)
{
    if( start_node->getRight() != nilNode() )
        return minimum(start_node->getRight());

    std::shared_ptr<TreeNode> temp_node = start_node;
    std::shared_ptr<TreeNode> successor = start_node->getParent();

    while( successor != nilNode() && temp_node == successor->getRight() )
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
    new_node->setColour(TreeNode::NodeColour::RED);

    while( insertion_parent != nilNode() )
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
        root_node = new_node;
        if( debug_out )
            printf("Tree was empty, setting the root to %d\n", new_node->getValue());
    }
    else
    {
        if( new_node->getValue() < temp_node->getValue() )
        {
            temp_node->setLeft( new_node );
            if( debug_out )
                printf("Setting the left of %d to be %d\n", temp_node->getValue(), new_node->getValue() );
        }
        else
        {
            temp_node->setRight( new_node );
            if( debug_out )
                printf("Setting the right of %d to be %d\n", temp_node->getValue(), new_node->getValue() );
        }
    }
    insertFixup(new_node);
    return new_node;
}
