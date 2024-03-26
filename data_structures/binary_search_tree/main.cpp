#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, char **argv)
{
    BinarySearchTree main_tree;
    int new_value;

    printf("\n--- populating tree ---\n");
    new_value = 15;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 22;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 17;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 2;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 5;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 45;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 12;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 6;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 4;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 100;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 120;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 88;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 67;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 54;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 32;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 29;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 33;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 97;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 44;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 86;
    printf("\tadding value %d\n", new_value);
    main_tree.addValue( new_value );

    printf("\n--- inOrderTreeWalk ---\n\t");
    BinarySearchTree::inOrderTreeWalk( main_tree.root );
    printf("\n");

    int target_value;
    TreeNode *target_node;

    printf("\n--- treeSearch ---\n");

    target_value = 17;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 13;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 15;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 120;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 122;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );


    printf("\n--- iterativeTreeSearch ---\n");

    target_value = 17;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 13;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 15;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 120;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );

    target_value = 122;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("\ttreeSearch for %d result %p\n", target_value, target_node );


    printf("\n--- treeMinimum ---\n");
    TreeNode *minimum_node = BinarySearchTree::treeMinimum( main_tree.root );
    printf("\tminimum node %p, value %d \n", minimum_node, minimum_node->value );

    printf("\n--- treeMaximum ---\n");
    TreeNode *maximum_node = BinarySearchTree::treeMaximum( main_tree.root );
    printf("\tmaximum node %p, value %d \n", maximum_node, maximum_node->value );

    TreeNode *candidate;
    TreeNode *successor;
    TreeNode *predecessor;
    TreeNode *root = main_tree.root;


    printf("\n--- treePredecessor tests ---\n");
    candidate = BinarySearchTree::treeSearch(root, 17 );
    predecessor = BinarySearchTree::treePredecessor( candidate );
    printf("\tpredecessor node to %d is %p, value %d \n", candidate->value, predecessor, predecessor->value );

    printf("\n--- treeSucessor tests ---\n");
    candidate = BinarySearchTree::treeSearch(root, 17 );
    successor = BinarySearchTree::treeSuccessor( candidate );
    printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor, successor->value );

    candidate = BinarySearchTree::treeSearch(root, 67 );
    successor = BinarySearchTree::treeSuccessor( candidate );
    if( successor != nullptr )
        printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor, successor->value );
    else
        printf("\tno successor node to %d\n", candidate->value );


    candidate = BinarySearchTree::treeSearch(root, 2 );
    successor = BinarySearchTree::treeSuccessor( candidate );
    if( successor != nullptr )
        printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor, successor->value );
    else
        printf("\tno successor node to %d\n", candidate->value );

    candidate = BinarySearchTree::treeSearch(root, 120 );
    successor = BinarySearchTree::treeSuccessor( candidate );
    if( successor != nullptr )
        printf("\tsuccessor node to %d is %p, value %d \n", candidate->value, successor, successor->value );
    else
        printf("\tno successor node to %d\n", candidate->value );

}
