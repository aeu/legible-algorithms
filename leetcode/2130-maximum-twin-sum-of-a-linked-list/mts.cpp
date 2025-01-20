// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include "ListNode.h"

std::shared_ptr<ListNode> buildList(std::vector<int> values )
{
    std::shared_ptr<ListNode> prev_node;
    std::shared_ptr<ListNode> next_node;
    std::shared_ptr<ListNode> root_node;
    bool first_time = true;

    for(int current : values )
    {
        if( first_time )
        {
            root_node = std::make_shared<ListNode>(current);
            prev_node = root_node;
            first_time = false;
        }
        else
        {
            next_node = std::make_shared<ListNode>(current);
            prev_node->setNext(next_node);
            prev_node = next_node;
        }
    }
    return root_node;
}


int main(int argc, char **argv)
{
    {
        std::vector<int> values = { 5,4,2,1};
        std::shared_ptr<ListNode> root_node = buildList(values);
        root_node->dumpNodes();
        std::shared_ptr<ListNode> lead_node = root_node;
        std::shared_ptr<ListNode> lead_node_previous = root_node;
        std::shared_ptr<ListNode> trailing_node = root_node;
        std::shared_ptr<ListNode> trailing_node_parent = root_node;
        bool should_advance_trailing_node = false;
        while( lead_node != nullptr )
        {
            if( should_advance_trailing_node )
            {
                trailing_node_parent = trailing_node;
                trailing_node = trailing_node_parent->getNext();
            }
            should_advance_trailing_node = ! should_advance_trailing_node;
            lead_node_previous = lead_node;
            lead_node = lead_node_previous->getNext();
        }

        trailing_node_parent->setNext(nullptr);
        // now I have to reverse the 2nd half of the list
        std::shared_ptr<ListNode> reversed_root = trailing_node;
        std::shared_ptr<ListNode> reversed_last = trailing_node;
        std::shared_ptr<ListNode> current = trailing_node->getNext();
        std::shared_ptr<ListNode> temp = nullptr;
        while( current )
        {
            temp = current;
            current = current->getNext();
            temp->setNext( reversed_root );
            reversed_root = temp;
        }
        reversed_last->setNext(nullptr);

        int max_twin_sum = 0;
        std::shared_ptr<ListNode> current_pair;

        int twin_sum = root_node->getValue() + reversed_root->getValue();
        max_twin_sum = std::max( max_twin_sum, twin_sum );
        current = root_node->getNext();
        current_pair = reversed_root->getNext();
        while( current )
        {
            twin_sum = current->getValue() + current_pair->getValue();
            max_twin_sum = std::max( max_twin_sum, twin_sum );
            current = current->getNext();
            current_pair = current_pair->getNext();
        }
        std::cout << "Max Twin Sum: " << max_twin_sum << std::endl;
    }
    {
        std::vector<int> values = { 4,2,2,3};
        std::shared_ptr<ListNode> root_node = buildList(values);
        root_node->dumpNodes();
        std::shared_ptr<ListNode> lead_node = root_node;
        std::shared_ptr<ListNode> lead_node_previous = root_node;
        std::shared_ptr<ListNode> trailing_node = root_node;
        std::shared_ptr<ListNode> trailing_node_parent = root_node;
        bool should_advance_trailing_node = false;
        while( lead_node != nullptr )
        {
            if( should_advance_trailing_node )
            {
                trailing_node_parent = trailing_node;
                trailing_node = trailing_node_parent->getNext();
            }
            should_advance_trailing_node = ! should_advance_trailing_node;
            lead_node_previous = lead_node;
            lead_node = lead_node_previous->getNext();
        }

        trailing_node_parent->setNext(nullptr);
        // now I have to reverse the 2nd half of the list
        std::shared_ptr<ListNode> reversed_root = trailing_node;
        std::shared_ptr<ListNode> reversed_last = trailing_node;
        std::shared_ptr<ListNode> current = trailing_node->getNext();
        std::shared_ptr<ListNode> temp = nullptr;
        while( current )
        {
            temp = current;
            current = current->getNext();
            temp->setNext( reversed_root );
            reversed_root = temp;
        }
        reversed_last->setNext(nullptr);

        int max_twin_sum = 0;
        std::shared_ptr<ListNode> current_pair;

        int twin_sum = root_node->getValue() + reversed_root->getValue();
        max_twin_sum = std::max( max_twin_sum, twin_sum );
        current = root_node->getNext();
        current_pair = reversed_root->getNext();
        while( current )
        {
            twin_sum = current->getValue() + current_pair->getValue();
            max_twin_sum = std::max( max_twin_sum, twin_sum );
            current = current->getNext();
            current_pair = current_pair->getNext();
        }
        std::cout << "Max Twin Sum: " << max_twin_sum << std::endl;
    }
    {
        std::vector<int> values = { 1,100000};
        std::shared_ptr<ListNode> root_node = buildList(values);
        root_node->dumpNodes();
        std::shared_ptr<ListNode> lead_node = root_node;
        std::shared_ptr<ListNode> lead_node_previous = root_node;
        std::shared_ptr<ListNode> trailing_node = root_node;
        std::shared_ptr<ListNode> trailing_node_parent = root_node;
        bool should_advance_trailing_node = false;
        while( lead_node != nullptr )
        {
            if( should_advance_trailing_node )
            {
                trailing_node_parent = trailing_node;
                trailing_node = trailing_node_parent->getNext();
            }
            should_advance_trailing_node = ! should_advance_trailing_node;
            lead_node_previous = lead_node;
            lead_node = lead_node_previous->getNext();
        }

        trailing_node_parent->setNext(nullptr);
        // now I have to reverse the 2nd half of the list
        std::shared_ptr<ListNode> reversed_root = trailing_node;
        std::shared_ptr<ListNode> reversed_last = trailing_node;
        std::shared_ptr<ListNode> current = trailing_node->getNext();
        std::shared_ptr<ListNode> temp = nullptr;
        while( current )
        {
            temp = current;
            current = current->getNext();
            temp->setNext( reversed_root );
            reversed_root = temp;
        }
        reversed_last->setNext(nullptr);

        int max_twin_sum = 0;
        std::shared_ptr<ListNode> current_pair;

        int twin_sum = root_node->getValue() + reversed_root->getValue();
        max_twin_sum = std::max( max_twin_sum, twin_sum );
        current = root_node->getNext();
        current_pair = reversed_root->getNext();
        while( current )
        {
            twin_sum = current->getValue() + current_pair->getValue();
            max_twin_sum = std::max( max_twin_sum, twin_sum );
            current = current->getNext();
            current_pair = current_pair->getNext();
        }
        std::cout << "Max Twin Sum: " << max_twin_sum << std::endl;
    }
}
