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
    TreeNode *base_of_insertion_point = nullptr;

    insertion_point = root;
    while( insertion_point != nullptr )
    {
	base_of_insertion_point = insertion_point;
	if( candidate->value < insertion_point->value )
	{
	    insertion_point = insertion_point->left;
	}
	else
	{
	    insertion_point = insertion_point->right;
	}
    }

    if( base_of_insertion_point == nullptr )
    {
	root = candidate;
    }
    else
    {
	if( candidate->value < base_of_insertion_point->value )
	{
	    base_of_insertion_point->left = candidate;
	}
	else
	{
	    base_of_insertion_point->right = candidate;
	}
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
