#include "stdio.h"
#include "BinarySearchTree.h"


void BinarySearchTree::addValue(int new_value)
{
    TreeNode *new_node = new TreeNode();
    new_node->value = new_value;
    this->insertNode( new_node );
}

void BinarySearchTree::inOrderTreeWalk(TreeNode *origin)
{
    if( origin != nullptr )
    {
	inOrderTreeWalk( origin->left );
	printf("%d ", origin->value );
	inOrderTreeWalk( origin->right );
    }
}

void BinarySearchTree::insertNode(TreeNode *candidate)
{
    TreeNode *insertion_point         = nullptr;
    TreeNode *insertion_points_parent = nullptr;

    insertion_point = root;
    while( insertion_point != nullptr )
    {
	insertion_points_parent = insertion_point;
	if( candidate->value < insertion_point->value )
	{
	    insertion_point = insertion_point->left;
	}
	else
	{
	    insertion_point = insertion_point->right;
	}
    }

    if( insertion_points_parent == nullptr )
    {
	root = candidate;
    }
    else
    {
	if( candidate->value < insertion_points_parent->value )
	{
	    insertion_points_parent->left = candidate;
	}
	else
	{
	    insertion_points_parent->right = candidate;
	}
        candidate->parent = insertion_points_parent;
    }
}

TreeNode *BinarySearchTree::iterativeTreeSearch(TreeNode *origin, int value)
{
    TreeNode *current = origin;
    while(( current != nullptr ) && ( current->value != value ))
    {
        if( value < current->value )
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return current;
}


TreeNode *BinarySearchTree::treeMinimum(TreeNode *origin)
{
    TreeNode *current_node = origin;
    while ( current_node->left != nullptr )
    {
        current_node = current_node->left;
    }
    return current_node;
}


TreeNode *BinarySearchTree::treeMaximum(TreeNode *origin)
{
    TreeNode *current_node = origin;
    while ( current_node->right != nullptr )
    {
        current_node = current_node->right;
    }
    return current_node;
}


TreeNode *BinarySearchTree::treeSearch(TreeNode *origin, int value)
{
    if( origin == nullptr )
	return nullptr;

    if( origin->value == value )
	return origin;

    if( value < origin->value )
	return BinarySearchTree::treeSearch( origin->left, value );
    else
	return BinarySearchTree::treeSearch( origin->right, value );

    return nullptr;
}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}
