// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <iostream>
#include "ListNode.h"

int main(int argc, char **argv)
{
    std::shared_ptr<ListNode> root_node = std::make_shared<ListNode>(42);
    std::shared_ptr<ListNode> next_node = std::make_shared<ListNode>(45);

    root_node->setNext(next_node);
    std::cout << "Root has value of : " << root_node->getValue() << std::endl;
    std::cout << "Root has next with value of : " << root_node->getNext()->getValue() << std::endl;

    std::shared_ptr<ListNode> new_root = std::make_shared<ListNode>(12,root_node);
    std::cout << "New root has value of : " << new_root->getValue() << std::endl;
    std::cout << "New root has next with value of : " << new_root->getNext()->getValue() << std::endl;

    new_root->dumpNodes();
    
}
