#include "stdio.h"
#include "BinarySearchTree.h"


TreeNode *BinarySearchTree::addValue(int new_value)
{
    TreeNode *new_node = new TreeNode();
    new_node->value = new_value;
    this->insertNode( new_node );
    return new_node;
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

TreeNode *BinarySearchTree::removeNode(TreeNode *z)
{
    if( z == nullptr )
        return nullptr;

    TreeNode *y;
    TreeNode *x;
    if(( z->left == nullptr ) || ( z->right == nullptr ))
    {
        y = z;
    }
    else
        y = treeSuccessor( z );

    if( y->left != nullptr )
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if( x != nullptr )
    {
        x->parent = y->parent;
    }
    if( y->parent == nullptr )
    {
        root = x;
    }
    else
    {
        if( y == y->parent->left )
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }
    if( y != z )
    {
        z->value = y->value;
    }
    return y;
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

TreeNode *BinarySearchTree::treePredecessor(TreeNode *current_node)
{
    if( current_node->left != nullptr )
        return BinarySearchTree::treeMaximum( current_node->left );

    TreeNode *x  = current_node;
    TreeNode *y  = x->parent;
    while(( y != nullptr ) && ( x == y->left ))
    {
        x = y;
        y = x->parent;
    }
    return y;
}

TreeNode *BinarySearchTree::treeSuccessor(TreeNode *current_node)
{
    if( current_node->right != nullptr )
        return BinarySearchTree::treeMinimum( current_node->right );

    TreeNode *x  = current_node;
    TreeNode *y  = x->parent;
    while(( y != nullptr ) && ( x == y->right ))
    {
        x = y;
        y = x->parent;
    }
    return y;
}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}
