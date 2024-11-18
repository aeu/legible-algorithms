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
    printf(" dot %s -Tpng > %s.png; open %s.png\n", filename, filename,filename );
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

void RedBlackTree::deleteFixup(std::shared_ptr<TreeNode> x )
{
    std::shared_ptr<TreeNode> w;
    while(( x != nilNode()) && (x->getColour() != TreeNode::NodeColour::BLACK ))
    {
        if( x == x->getParent()->getLeft() )
        {
            w = x->getParent()->getRight();
            if( w->getColour() == TreeNode::NodeColour::RED )
            {
                w->setColour(TreeNode::NodeColour::BLACK);
                x->getParent()->setColour(TreeNode::NodeColour::RED);
                leftRotate(x->getParent());
                w = x->getParent()->getRight();
            }
            if(( w->getLeft()->getColour() == TreeNode::NodeColour::BLACK )
               && ( w->getRight()->getColour() == TreeNode::NodeColour::BLACK ))
            {
                w->setColour(TreeNode::NodeColour::RED);
                x = x->getParent();
            }
            else
            {
                if( w->getRight()->getColour() == TreeNode::NodeColour::BLACK )
                {
                    w->getLeft()->setColour( TreeNode::NodeColour::BLACK );
                    w->setColour( TreeNode::NodeColour::RED );
                    rightRotate(w);
                    w = x->getParent()->getRight();
                }
                w->setColour( x->getParent()->getColour());
                x->getParent()->setColour(TreeNode::NodeColour::BLACK );
                w->getRight()->setColour(TreeNode::NodeColour::BLACK);
                leftRotate(x->getParent());
                x = root_node;
            }
        }
        else
        {
            w = x->getParent()->getLeft();
            if( w->getColour() == TreeNode::NodeColour::RED )
            {
                w->setColour(TreeNode::NodeColour::BLACK);
                x->getParent()->setColour(TreeNode::NodeColour::RED);
                rightRotate(x->getParent());
                w = x->getParent()->getLeft();
            }
            if(( w->getRight()->getColour() == TreeNode::NodeColour::BLACK )
               && ( w->getLeft()->getColour() == TreeNode::NodeColour::BLACK ))
            {
                w->setColour(TreeNode::NodeColour::RED);
                x = x->getParent();
            }
            else
            {
                if( w->getLeft()->getColour() == TreeNode::NodeColour::BLACK )
                {
                    w->getRight()->setColour( TreeNode::NodeColour::BLACK );
                    w->setColour( TreeNode::NodeColour::RED );
                    leftRotate(w);
                    w = x->getParent()->getLeft();
                }
                w->setColour( x->getParent()->getColour());
                x->getParent()->setColour(TreeNode::NodeColour::BLACK );
                w->getLeft()->setColour(TreeNode::NodeColour::BLACK);
                rightRotate(x->getParent());
                x = root_node;
            }
        }
    }
    x->setColour(TreeNode::NodeColour::BLACK);
}



void RedBlackTree::insertFixup(std::shared_ptr<TreeNode> z )
{
    std::shared_ptr<TreeNode> y = nilnode;
    std::shared_ptr<TreeNode> grandparent = nilnode;
    std::shared_ptr<TreeNode> parent = nilnode;
    std::shared_ptr<TreeNode> temp;
    int max = 0;
    while(( getParent(z) != nilnode ) && ( getParent(z)->getColour() == TreeNode::NodeColour::RED ))
    {
        grandparent = getGrandparent( z );
        if( grandparent == nilnode )
            continue;

        if( getParent(z) == grandparent->getLeft() )
        {
            y = grandparent->getRight();

            if(( y != nilnode ) && ( y->getColour() == TreeNode::NodeColour::RED ))
            {
                getParent(z)->setColour( TreeNode::NodeColour::BLACK );
                y->setColour( TreeNode::NodeColour::BLACK );
                grandparent->setColour( TreeNode::NodeColour::RED );
                z = grandparent;
            }
            else
            {
                if( z == getParent(z)->getRight())
                {
                    z = getParent(z);
                    leftRotate(z);
                }
            }
            getParent(z)->setColour( TreeNode::NodeColour::BLACK );
            grandparent = getGrandparent(z);
            if( grandparent != nilnode )
            {
                grandparent->setColour(  TreeNode::NodeColour:: RED );
                rightRotate(grandparent);
            }
        }
        else
        {
            y = grandparent->getLeft();
            if(( y != nilnode ) && ( y->getColour() == TreeNode::NodeColour::RED ))
            {
                getParent(z)->setColour( TreeNode::NodeColour::BLACK );
                y->setColour( TreeNode::NodeColour::BLACK );
                grandparent->setColour( TreeNode::NodeColour::RED );
                z = grandparent;
            }
            else
            {
                if( z == getParent(z)->getLeft())
                {
                    z = getParent(z);
                    rightRotate(z);
                }
            }
            getParent(z)->setColour( TreeNode::NodeColour::BLACK );
            grandparent = getGrandparent(z);
            if( grandparent != nilnode )
            {
                grandparent->setColour(  TreeNode::NodeColour:: RED );
                leftRotate(grandparent);
            }

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

std::shared_ptr<TreeNode> RedBlackTree::deleteNode(std::shared_ptr<TreeNode> z)
{
    printf("trying to delete %d\n", z->getValue());
    std::shared_ptr<TreeNode> x;
    std::shared_ptr<TreeNode> y;
    y = z;
    printf("\tsetting y to be %d\n", z->getValue());
    auto y_original_colour = y->getColour();
    if( z->getLeft() == nilNode() )
    {
        printf("\t%d had a left child of nilnode\n", z->getValue());
        x = z->getRight();
        transplant( z, z->getRight() );
    }
    else if ( z->getRight() == nilNode() )
    {
        printf("\t%d had a right child of nilnode\n", z->getValue());
        x = z->getLeft();
        transplant( z, z->getLeft() );
    }
    else
    {
        printf("\t%d didn't have any nilnode children, it's children were L:%d and R:%d\n", z->getValue(), z->getLeft()->getValue(), z->getRight()->getValue());
        y = minimum( z->getRight() );
        y_original_colour = y->getColour();
        x = y->getRight();
        if( y->getParent() == z )
        {
            printf("\t%d's parent was %d\n", y->getParent()->getValue(), z->getValue());
            x->setParent( y );
        }
        else
        {
            printf("\t%d's parent was NOT %d\n", y->getParent()->getValue(), z->getValue());
            transplant(y, y->getRight() );
            y->setRight(z->getRight() );
            y->getRight()->setParent( y );
        }
        transplant(z,y);
        y->setLeft(z->getLeft() );
        y->getLeft()->setParent( y );
        y->setColour( z->getColour() );
    }
    if( y_original_colour == TreeNode::NodeColour::BLACK )
        printf("here I should call fixup\n");

    return z;
}

std::shared_ptr<TreeNode> RedBlackTree::removeValue(int value)
{
    printf("\ntrying to remove %d\n", value );
    std::shared_ptr<TreeNode> removed = find(value);
    if( removed == nilNode() )
    {
        printf("did not find the node\n");
        return nilNode();
    }

    return deleteNode( removed );
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


void RedBlackTree::transplant(std::shared_ptr<TreeNode> original,
                              std::shared_ptr<TreeNode> replacement)
{
    printf("transplanting %d with %d\n", original->getValue(), replacement->getValue());
    if( original->getParent() == nilNode() )
    {
        printf("\t%d's parent was nilnode", original->getValue());
        root_node = replacement;
    }
    else if ( original == original->getParent()->getLeft() )
    {
        printf("\t%d was %d's left child\n", original->getValue(), original->getParent()->getValue());
        original->getParent()->setLeft( replacement );
    }
    else
    {
        printf("\t%d was %d's right child\n", original->getValue(), original->getParent()->getValue());
        original->getParent()->setRight( replacement );
    }
    printf("\tsetting %d's parent to be %d\n", replacement->getValue(), original->getParent()->getValue());
    replacement->setParent( original->getParent() );
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
    }
    else
    {
        if( new_node->getValue() < temp_node->getValue() )
        {
            temp_node->setLeft( new_node );
        }
        else
        {
            temp_node->setRight( new_node );
        }
    }
    insertFixup(new_node);
    return new_node;
}
