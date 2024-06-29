#include <memory>
#include "stdio.h"
#include "BinarySearchTree.h"


std::shared_ptr<TreeNode> BinarySearchTree::addValue(int new_value)
{
    std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>();
    new_node.get()->value = new_value;
    this->insertNode( new_node );
    return new_node;
}

void BinarySearchTree::inOrderTreeWalk(std::shared_ptr<TreeNode> origin)
{
    if( origin != nullptr )
    {
	inOrderTreeWalk( origin->left );
	printf("%d ", origin->value );
	inOrderTreeWalk( origin->right );
    }
}

std::shared_ptr<TreeNode> BinarySearchTree::removeNode(std::shared_ptr<TreeNode> removal_candidate)
{
    std::shared_ptr<TreeNode> deleted_node;
    std::shared_ptr<TreeNode> temporary_node;

    if( removal_candidate == nullptr )
        return nullptr;

    if(( removal_candidate->left == nullptr ) || ( removal_candidate->right == nullptr ))
    {
        deleted_node = removal_candidate;
    }
    else
    {
        deleted_node = treeSuccessor( removal_candidate );
    }

    if( deleted_node->left != nullptr )
    {
        temporary_node = deleted_node->left;
    }
    else
    {
        temporary_node = deleted_node->right;
    }

    if( temporary_node != nullptr )
    {
        temporary_node->parent = deleted_node->parent;
    }
    if( deleted_node->parent == nullptr )
    {
        root = temporary_node;
    }
    else
    {
        if( deleted_node == deleted_node->parent->left )
        {
            deleted_node->parent->left = temporary_node;
        }
        else
        {
            deleted_node->parent->right = temporary_node;
        }
    }
    if( deleted_node != removal_candidate )
    {
        removal_candidate->value = deleted_node->value;
    }
    return deleted_node;
}


void BinarySearchTree::insertNode(std::shared_ptr<TreeNode> candidate)
{
    std::shared_ptr<TreeNode> insertion_point = nullptr;
    std::shared_ptr<TreeNode> insertion_points_parent = nullptr;

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

std::shared_ptr<TreeNode> BinarySearchTree::iterativeTreeSearch(std::shared_ptr<TreeNode> origin, int value)
{
    std::shared_ptr<TreeNode> current = origin;
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


std::shared_ptr<TreeNode> BinarySearchTree::treeMinimum(std::shared_ptr<TreeNode> origin)
{
    std::shared_ptr<TreeNode> current_node = origin;
    while ( current_node->left != nullptr )
    {
        current_node = current_node->left;
    }
    return current_node;
}


std::shared_ptr<TreeNode> BinarySearchTree::treeMaximum(std::shared_ptr<TreeNode> origin)
{
    std::shared_ptr<TreeNode> current_node = origin;
    while ( current_node->right != nullptr )
    {
        current_node = current_node->right;
    }
    return current_node;
}


std::shared_ptr<TreeNode> BinarySearchTree::treeSearch(std::shared_ptr<TreeNode> origin, int value)
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

std::shared_ptr<TreeNode> BinarySearchTree::treePredecessor(std::shared_ptr<TreeNode> current_node)
{
    if( current_node->left != nullptr )
        return BinarySearchTree::treeMaximum( current_node->left );

    std::shared_ptr<TreeNode> x  = current_node;
    std::shared_ptr<TreeNode> y  = x->parent;
    while(( y != nullptr ) && ( x == y->left ))
    {
        x = y;
        y = x->parent;
    }
    return y;
}

std::shared_ptr<TreeNode> BinarySearchTree::treeSuccessor(std::shared_ptr<TreeNode> current_node)
{
    if( current_node->right != nullptr )
        return BinarySearchTree::treeMinimum( current_node->right );

    std::shared_ptr<TreeNode> x  = current_node;
    std::shared_ptr<TreeNode> y  = x->parent;
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
