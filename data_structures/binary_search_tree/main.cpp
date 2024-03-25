#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, char **argv)
{
    printf("main\n");
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

    printf("\n--- inOrderTreeWalk ---\n");
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
}
