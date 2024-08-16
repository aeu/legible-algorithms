#include "RedBlackTree.h"
#include <stdio.h>
#include <memory>

RedBlackTree::RedBlackTree()
{
    this->nilnode = std::make_shared<TreeNode>(-1);
    this->root_node = nullptr;
    printf("Created an empty red black tree\n");
}

std::shared_ptr<TreeNode> RedBlackTree::insert(std::shared_ptr<TreeNode> new_node)
{
    std::shared_ptr<TreeNode> temp_node = nullptr;
    std::shared_ptr<TreeNode> insertion_parent = this->root_node;
    while( insertion_parent != nullptr )
    {
        temp_node = insertion_parent;
        if( new_node->getValue() < insertion_parent->getValue() )
            insertion_parent = insertion_parent->getLeft();
        else
            insertion_parent = insertion_parent->getRight();
    }
    new_node->setParent(temp_node);
    if( temp_node == nullptr )
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


std::shared_ptr<TreeNode> RedBlackTree::maximum()
{
    std::shared_ptr<TreeNode> maximum = root_node;
    while( maximum != nullptr && maximum->getRight() != nullptr )
    {
        maximum = maximum->getRight();
    }
    return maximum;
}
std::shared_ptr<TreeNode> RedBlackTree::minimum()
{
    return nullptr;
}


std::shared_ptr<TreeNode> RedBlackTree::addValue(int new_value)
{
    std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>(new_value);
    insert(new_node);
    return new_node;
}
