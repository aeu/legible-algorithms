#include <stdio.h>
#include "BinarySearchTree.h"


void testAddValue(BinarySearchTree *main_tree, int new_value)
{
    std::shared_ptr<TreeNode> new_node = main_tree->addValue( new_value );
    printf("\tadding value %3d \t(%p)\n", new_value, new_node.get());
}



void testRemoveValue(BinarySearchTree *main_tree, int new_value)
{
    printf("Remove Test, removing : %d\nBefore: ", new_value);
    BinarySearchTree::inOrderTreeWalk( main_tree->root );
    std::shared_ptr<TreeNode> remove = BinarySearchTree::treeSearch( main_tree->root, new_value );
    main_tree->removeNode( remove );
    printf("\nAfter: ");
    BinarySearchTree::inOrderTreeWalk( main_tree->root );
    printf("\n\n");
}



void testTreeSearch(BinarySearchTree *main_tree, int target_value)
{
    std::shared_ptr<TreeNode> target_node = BinarySearchTree::treeSearch( main_tree->root, target_value );
    printf("\ttreeSearch for %3d result \t%p\n", target_value, target_node.get() );
}

void testIterativeTreeSearch(BinarySearchTree *main_tree, int target_value)
{
    std::shared_ptr<TreeNode> target_node = BinarySearchTree::iterativeTreeSearch( main_tree->root, target_value );
    printf("\titerativeTreeSearch for %3d result \t%p\n", target_value, target_node.get() );
}


void testTreePredecessor(BinarySearchTree *main_tree, int target_value)
{
    std::shared_ptr<TreeNode> candidate;
    std::shared_ptr<TreeNode> successor;
    std::shared_ptr<TreeNode> predecessor;
    std::shared_ptr<TreeNode> root = main_tree->root;
    candidate = BinarySearchTree::treeSearch(root, target_value );

    if( candidate == nullptr )
    {
        printf("\t candidate %d not found in tree, no predecessor node can be found\n", target_value);
        return;
    }
    predecessor = BinarySearchTree::treePredecessor( candidate );
    if( predecessor != nullptr )
        printf("\tpredecessor node to %d is %p, value %d \n", candidate->value, predecessor.get(), predecessor->value );
    else
        printf("\tno predecessor found for %d \n", target_value );
}

void testTreeSuccessor(BinarySearchTree *main_tree, int target_value)
{
    std::shared_ptr<TreeNode> candidate;
    std::shared_ptr<TreeNode> successor;
    std::shared_ptr<TreeNode> predecessor;
    std::shared_ptr<TreeNode> root = main_tree->root;
    candidate = BinarySearchTree::treeSearch(root, target_value );

    if( candidate == nullptr )
    {
        printf("\t candidate %d not found in tree, no successor node can be found\n", target_value);
        return;
    }
    successor = BinarySearchTree::treeSuccessor( candidate );
    if( successor != nullptr )
        printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor.get(), successor->value );
    else
        printf("\tno successor found for %d \n", target_value );
}


int main(int argc, char **argv)
{
    BinarySearchTree main_tree;
    int new_value;

    printf("\n--- populating tree ---\n");
    testAddValue(&main_tree, 15 );
    testAddValue(&main_tree, 22 );
    testAddValue(&main_tree, 17 );
    testAddValue(&main_tree, 2 );
    testAddValue(&main_tree, 5 );
    testAddValue(&main_tree, 45 );
    testAddValue(&main_tree, 12 );
    testAddValue(&main_tree, 6 );
    testAddValue(&main_tree, 4 );
    testAddValue(&main_tree, 100 );
    testAddValue(&main_tree, 120 );
    testAddValue(&main_tree, 88 );
    testAddValue(&main_tree, 67 );
    testAddValue(&main_tree, 54 );
    testAddValue(&main_tree, 32 );
    testAddValue(&main_tree, 29 );
    testAddValue(&main_tree, 33 );
    testAddValue(&main_tree, 97 );
    testAddValue(&main_tree, 44 );
    testAddValue(&main_tree, 86 );

    printf("\n--- inOrderTreeWalk ---\n\t");
    BinarySearchTree::inOrderTreeWalk( main_tree.root );
    printf("\n");

    int target_value;
    std::shared_ptr<TreeNode> target_node;

    printf("\n--- treeSearch ---\n");
    testTreeSearch(&main_tree, 17);
    testTreeSearch(&main_tree, 13);
    testTreeSearch(&main_tree, 15);
    testTreeSearch(&main_tree, 120);
    testTreeSearch(&main_tree, 122);
    testTreeSearch(&main_tree, 43);

    printf("\n--- iterativeTreeSearch ---\n");

    testIterativeTreeSearch(&main_tree, 23);
    testIterativeTreeSearch(&main_tree, 17);
    testIterativeTreeSearch(&main_tree, 13);
    testIterativeTreeSearch(&main_tree, 15);
    testIterativeTreeSearch(&main_tree, 120);
    testIterativeTreeSearch(&main_tree, 122);

    printf("\n--- treeMinimum ---\n");
    std::shared_ptr<TreeNode> minimum_node = BinarySearchTree::treeMinimum( main_tree.root );
    printf("\tminimum node %p, value %d \n", minimum_node.get(), minimum_node->value );

    printf("\n--- treeMaximum ---\n");
    std::shared_ptr<TreeNode> maximum_node = BinarySearchTree::treeMaximum( main_tree.root );
    printf("\tmaximum node %p, value %d \n", maximum_node.get(), maximum_node->value );


    printf("\n--- treePredecessor tests ---\n");
    testTreePredecessor(&main_tree, 17);
    testTreePredecessor(&main_tree, 15);
    testTreePredecessor(&main_tree, 120);

    printf("\n--- treeSucessor tests ---\n");
    testTreeSuccessor(&main_tree, 17);
    testTreeSuccessor(&main_tree, 15);
    testTreeSuccessor(&main_tree, 120);



    printf("\n--- remove tests ---\n");
    testRemoveValue(&main_tree, 15 );
    testRemoveValue(&main_tree, 22 );
    testRemoveValue(&main_tree, 17 );
    testRemoveValue(&main_tree, 500 );
    testRemoveValue(&main_tree, 2 );
    testRemoveValue(&main_tree, 5 );
    testRemoveValue(&main_tree, 45 );
    testRemoveValue(&main_tree, 12 );
    testRemoveValue(&main_tree, 6 );
    testRemoveValue(&main_tree, 4 );
    testRemoveValue(&main_tree, 100 );
    testRemoveValue(&main_tree, 120 );
    testRemoveValue(&main_tree, 88 );
    testRemoveValue(&main_tree, 67 );
    testRemoveValue(&main_tree, 54 );
    testRemoveValue(&main_tree, 32 );
    testRemoveValue(&main_tree, 29 );
    testRemoveValue(&main_tree, 33 );
    testRemoveValue(&main_tree, 97 );
    testRemoveValue(&main_tree, 44 );
    testRemoveValue(&main_tree, 86 );
}
