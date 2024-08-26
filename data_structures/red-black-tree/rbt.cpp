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
    if( ( 1 ) || ( 1 ) )
        printf("asdf\n");
    RedBlackTree temp2;
    std::shared_ptr<TreeNode> fifteen = temp2.addValue(15);

    temp2.addValue( 22  );
    std::shared_ptr<TreeNode> seventeen = temp2.addValue( 17 );
    temp2.addValue( 2   );
    temp2.addValue( 5   );
    temp2.addValue( 45  );
    temp2.addValue( 12  );
    temp2.addValue( 6   );
    temp2.addValue( 4   );
    temp2.addValue( 100 );
    temp2.addValue( 120 );
    temp2.addValue( 88  );
    temp2.addValue( 67  );
    std::shared_ptr<TreeNode> fifty_four = temp2.addValue( 54 );
    temp2.addValue( 32  );
    temp2.addValue( 29  );
    temp2.addValue( 33  );
    temp2.addValue( 97  );
    temp2.addValue( 44  );
    temp2.addValue( 86  );

    // std::shared_ptr<TreeNode> seven = temp2.addValue(7);
    // temp2.addValue(10);
    // temp2.addValue(12);
    // temp2.addValue(13);
    // temp2.addValue(47);
    // std::shared_ptr<TreeNode> sixteen = temp2.addValue(16);
    // temp2.addValue(20);
    // temp2.addValue(18);
    // temp2.addValue(23);

    // {
    //     std::shared_ptr<TreeNode> maximum = temp2.maximum(nullptr);
    //     printf("the max node was : %d \n", maximum->getValue());
    // }

    // {
    //     std::shared_ptr<TreeNode> minimum = temp2.minimum(nullptr);
    //     printf("the min node was : %d \n", minimum->getValue());
    // }

    // {
    //     std::shared_ptr<TreeNode> maximum = temp2.maximum(sixteen);
    //     printf("the max node under 16 was : %d \n", maximum->getValue());
    // }

    // {
    //     std::shared_ptr<TreeNode> minimum = temp2.minimum(seven);
    //     printf("the min node under 7 was : %d \n", minimum->getValue());
    // }

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

    RedBlackTree::inOrderTreeWalk(temp2.root_node);
    printf("\n");

    std::shared_ptr<TreeNode> found = temp2.find(4);
    if( found != nullptr )
    {
        printf("found, value was %d\n", found->getValue());
    }

    temp2.remove(4);
    RedBlackTree::inOrderTreeWalk(temp2.root_node);
    printf("\n");

}
