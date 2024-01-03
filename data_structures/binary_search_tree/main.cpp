#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, char **argv)
{
    printf("main\n");
    BinarySearchTree main_tree;
    main_tree.addValue( 15 );
    main_tree.addValue( 6 );
    main_tree.addValue( 18 );
    main_tree.addValue( 3 );
    main_tree.addValue( 7 );
    main_tree.addValue( 17 );
    main_tree.addValue( 20 );
    main_tree.addValue( 2 );
    main_tree.addValue( 4 );
    main_tree.addValue( 13 );
    main_tree.addValue( 9 );


    printf("inOrderTreeWalk\n");
    BinarySearchTree::inOrderTreeWalk( main_tree.root );
}
