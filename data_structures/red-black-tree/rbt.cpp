#include <stdio.h>
#include "TreeNode.h"
#include "RedBlackTree.h"


int main(int argc, char **argv)
{
    RedBlackTree temp2;
    temp2.addValue(15);
    temp2.addValue(6);
    //    temp2.addValue(5);
    temp2.addValue(3);
    temp2.addValue(7);
    temp2.addValue(10);
    temp2.addValue(12);
    temp2.addValue(13);
    temp2.addValue(16);
    temp2.addValue(20);
    temp2.addValue(18);
    temp2.addValue(23);


    std::shared_ptr<TreeNode> maximum = temp2.maximum(nullptr);
    printf("the max node was : %d \n", maximum->getValue());
}
