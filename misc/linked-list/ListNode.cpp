// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include "ListNode.h"

ListNode::ListNode()
{
    value = 0;
    next = nullptr;
}
ListNode::ListNode(const int node_value)
{
    value = node_value;
    next = nullptr;
}

ListNode::ListNode(const int node_value,
                   std::shared_ptr<ListNode> next_value)
{
    value = node_value;
    next = next_value;
}

std::shared_ptr<ListNode> ListNode::getNext()
{
    return next;
}
std::shared_ptr<ListNode> ListNode::setNext(std::shared_ptr<ListNode> next_value)
{
    next = next_value;
    return next;
}

int ListNode::getValue()
{
    return value;
}

int ListNode::setValue(const int new_value)
{
    value = new_value;
    return value;
}

void ListNode::dumpNodes()
{
    bool first_time = true;
    std::cout << "[";
    std::shared_ptr<ListNode> next_node;

    next_node = next;
    while( next_node != nullptr )
    {
        if( ! first_time )
            std::cout << ", " ;

        if( first_time )
            std::cout << getValue();
        else
        {
            std::cout << next_node->getValue();
            next_node = next_node->getNext();
        }
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

