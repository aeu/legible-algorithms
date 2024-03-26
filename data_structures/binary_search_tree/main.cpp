#include <stdio.h>
#include "BinarySearchTree.h"


void testAddValue(BinarySearchTree *main_tree, int new_value)
{
    printf("\tadding value %d\n", new_value);
    main_tree->addValue( new_value );
}

void testTreeSearch(BinarySearchTree *main_tree, int target_value)
{
    TreeNode *target_node = BinarySearchTree::treeSearch( main_tree->root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );
}

void testIterativeTreeSearch(BinarySearchTree *main_tree, int target_value)
{
    TreeNode *target_node = BinarySearchTree::iterativeTreeSearch( main_tree->root, target_value );
    printf("\titerativeTreeSearch for %d result %p\n", target_value, target_node );
}

void testTreePredecessor(BinarySearchTree *main_tree, int target_value)
{
    TreeNode *candidate;
    TreeNode *successor;
    TreeNode *predecessor;
    TreeNode *root = main_tree->root;
    candidate = BinarySearchTree::treeSearch(root, target_value );

    if( candidate == nullptr )
    {
        printf("\t candidate %d not found in tree, no predecessor node can be found\n", target_value);
        return;
    }
    predecessor = BinarySearchTree::treePredecessor( candidate );
    if( predecessor != nullptr )
        printf("\tpredecessor node to %d is %p, value %d \n", candidate->value, predecessor, predecessor->value );
    else
        printf("\tno predecessor found for %d \n", target_value );
}

void testTreeSuccessor(BinarySearchTree *main_tree, int target_value)
{
    TreeNode *candidate;
    TreeNode *successor;
    TreeNode *predecessor;
    TreeNode *root = main_tree->root;
    candidate = BinarySearchTree::treeSearch(root, target_value );

    if( candidate == nullptr )
    {
        printf("\t candidate %d not found in tree, no successor node can be found\n", target_value);
        return;
    }
    successor = BinarySearchTree::treeSuccessor( candidate );
    if( successor != nullptr )
        printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor, successor->value );
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
    TreeNode *target_node;

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
    TreeNode *minimum_node = BinarySearchTree::treeMinimum( main_tree.root );
    printf("\tminimum node %p, value %d \n", minimum_node, minimum_node->value );

    printf("\n--- treeMaximum ---\n");
    TreeNode *maximum_node = BinarySearchTree::treeMaximum( main_tree.root );
    printf("\tmaximum node %p, value %d \n", maximum_node, maximum_node->value );

    printf("\n--- treePredecessor tests ---\n");
    testTreePredecessor(&main_tree, 17);
    testTreePredecessor(&main_tree, 15);
    testTreePredecessor(&main_tree, 120);

    printf("\n--- treeSucessor tests ---\n");
    testTreeSuccessor(&main_tree, 17);
    testTreeSuccessor(&main_tree, 15);
    testTreeSuccessor(&main_tree, 120);

}
