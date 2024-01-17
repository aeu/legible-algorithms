#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, char **argv)
{
    printf("main\n");
    BinarySearchTree main_tree;
    int new_value;

    new_value = 15;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 22;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 17;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 2;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 5;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 45;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 12;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 6;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 4;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 100;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 120;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 88;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 67;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 45;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 54;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 32;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 29;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 33;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 97;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 44;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    new_value = 86;
    printf("adding value %d\n", new_value);
    main_tree.addValue( new_value );

    printf("--- inOrderTreeWalk ---\n");
    BinarySearchTree::inOrderTreeWalk( main_tree.root );
    printf("\n");

    int target_value;
    TreeNode *target_node;

    printf("--- treeSearch ---\n");

    target_value = 17;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 13;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 15;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 120;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 122;
    target_node = BinarySearchTree::treeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );


    printf("--- iterativeTreeSearch ---\n");

    target_value = 17;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 13;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 15;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 120;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );

    target_value = 122;
    target_node = BinarySearchTree::iterativeTreeSearch( main_tree.root, target_value );
    printf("treeSearch for %d result %p\n", target_value, target_node );
}
