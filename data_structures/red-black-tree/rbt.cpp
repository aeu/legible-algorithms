// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include "TreeNode.h"
#include "RedBlackTree.h"


int main(int argc, char **argv)
{
    char filename[255];
    int file_index = 1;
    RedBlackTree temp2;

    std::shared_ptr<TreeNode> fifteen = temp2.addValue(11);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(2);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(14);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(1);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(7);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(15);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(5);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    // temp2.addValue(8);
    // sprintf(filename,"%03d.dot",file_index++);
    // temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(4);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(33);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    // temp2.addValue(19);
    // sprintf(filename,"%03d.dot",file_index++);
    // temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(3);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    // temp2.addValue(27);
    // sprintf(filename,"%03d.dot",file_index++);
    // temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(24);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(45);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(31);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(54);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(28);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(22);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(46);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(36);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());


    temp2.addValue(44);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(23);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(41);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.addValue(17);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(33);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(17);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(41);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(54);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(22);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.removeValue(28);
    sprintf(filename,"%03d.dot",file_index++);
    temp2.toDotFile( filename, temp2.nilNode());

    temp2.inOrderTreeWalk(temp2.root_node);
    printf("\n");

#if 0

    {
        std::shared_ptr<TreeNode> maximum = temp2.maximum( temp2.nilNode());
        printf("the max node of the whole tree was : %d \n", maximum->getValue());
    }

    {
        std::shared_ptr<TreeNode> minimum = temp2.minimum(temp2.nilNode());
        printf("the min node of the whole tree was : %d \n", minimum->getValue());
    }

    {
        std::shared_ptr<TreeNode> maximum = temp2.maximum(fifty_four);
        printf("the max node under 54 was : %d \n", maximum->getValue());
    }

    {
        std::shared_ptr<TreeNode> minimum = temp2.minimum(seventeen);
        printf("the min node under 17 was : %d \n", minimum->getValue());
    }

    printf("\n\nPredecessor / Successor Tests\n");
    {
        std::shared_ptr<TreeNode> successor = temp2.successor(fifty_four);
        printf("The successor of 54 was : %d \n", successor->getValue());
    }

    {
        std::shared_ptr<TreeNode> predecessor = temp2.predecessor(fifty_four);
        printf("The predecessor of 54 was : %d \n", predecessor->getValue());
    }

    {
        std::shared_ptr<TreeNode> successor = temp2.successor(seventeen);
        printf("The successor of 17 was : %d \n", successor->getValue());
    }

    {
        std::shared_ptr<TreeNode> predecessor = temp2.predecessor(seventeen);
        printf("The predecessor of 17 was : %d \n", predecessor->getValue());
    }

    printf("\n");

    printf("TreeRotate Tests\n");
    printf(" Rotations:                                                    \n");
    printf("                                                               \n");
    printf("               |                                      |        \n");
    printf("               y                                      x        \n");
    printf("              / \\        <--- Left Rotate T,x        / \\     \n");
    printf("             /   \\       T,y  Right Rotate --->     /   \\    \n");
    printf("            x     γ                                α     y     \n");
    printf("           / \\                                          / \\  \n");
    printf("          /   \\                                        /   \\ \n");
    printf("         α     β                                      β     γ  \n");
    printf("                                                               \n");


    {
        printf("Left Rotate\n");
        printf("Starting with node  x(%d)\n", five->getValue());
        printf("\t(x) Left: %d   (x) Right: %d\n", five->getLeft()->getValue(), five->getRight()->getValue());
        std::shared_ptr<TreeNode> new_right = temp2.leftRotate( five );
        printf("\tAfter rotation (x) Left: %d, (x) Right %d\n", five->getLeft()->getValue(), five->getRight()->getValue());
        printf("\ty(%d),  (y) Left %d :   (y) Right : %d\n", new_right->getValue(), new_right->getLeft()->getValue(), new_right->getRight()->getValue());
    }

    {
        printf("Right Rotate\n");
        printf("Starting with node y(%d)\n", eighty_eight->getValue());
        printf("\t(y) Left: %d   (y) Right: %d\n", eighty_eight->getLeft()->getValue(), eighty_eight->getRight()->getValue());
        std::shared_ptr<TreeNode> new_left = temp2.rightRotate( eighty_eight );
        printf("\tAfter rotation Left: %d, Right %d\n", eighty_eight->getLeft()->getValue(), eighty_eight->getRight()->getValue());
        printf("\tNew Left : %d,  its left %d :   its right : %d\n", new_left->getValue(), new_left->getLeft()->getValue(), new_left->getRight()->getValue());
    }


    {
        temp2.inOrderTreeWalk(temp2.root_node);
        std::shared_ptr<TreeNode> removed_node = temp2.remove(4);
        temp2.inOrderTreeWalk(temp2.root_node);
    }
    {
        std::shared_ptr<TreeNode> removed_node = temp2.remove(2);
        temp2.inOrderTreeWalk(temp2.root_node);
    }
    {
        std::shared_ptr<TreeNode> removed_node = temp2.remove(32);
        temp2.inOrderTreeWalk(temp2.root_node);
    }
    {
        std::shared_ptr<TreeNode> removed_node = temp2.remove(100);
        temp2.inOrderTreeWalk(temp2.root_node);
    }
    {
        std::shared_ptr<TreeNode> removed_node = temp2.remove(17);
        temp2.inOrderTreeWalk(temp2.root_node);
    }
    printf("\n");
    temp2.toDotFile("rbt.dot", temp2.nilNode());
#endif    
}
