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
        // setup
        std::vector<int> values = { 1,2,3,4,5};
        std::shared_ptr<ListNode> root_node = buildList(values);
        
        root_node->dumpNodes();

        std::shared_ptr<ListNode> odd_root;
        std::shared_ptr<ListNode> odd_tail;
        std::shared_ptr<ListNode> even_root;
        std::shared_ptr<ListNode> even_tail;
        std::shared_ptr<ListNode> current;

        bool is_odd = true;
        current = root_node;
        while( current != nullptr )
        {
            if( is_odd )
            {
                if( odd_root == nullptr )
                {
                    odd_root = current;
                    odd_tail = current;
                }
                else
                {
                    odd_tail->setNext(current);
                    odd_tail = current;
                }
            }
            else
            {
                if( even_root == nullptr )
                {
                   even_root = current;
                   even_tail = current;
                }
                else
                {
                    even_tail->setNext(current);
                    even_tail = current;
                }
            }
            is_odd = ! is_odd;
            current = current->getNext();
        }
        root_node = odd_root;
        odd_tail->setNext(even_root);
        even_tail->setNext(nullptr);
        root_node->dumpNodes();
        
    }
    {
        // setup
        std::vector<int> values = { 2,1,3,5,6,4,7};
        std::shared_ptr<ListNode> root_node = buildList(values);
        
        root_node->dumpNodes();

        std::shared_ptr<ListNode> odd_root;
        std::shared_ptr<ListNode> odd_tail;
        std::shared_ptr<ListNode> even_root;
        std::shared_ptr<ListNode> even_tail;
        std::shared_ptr<ListNode> current;

        bool is_odd = true;
        current = root_node;
        while( current != nullptr )
        {
            if( is_odd )
            {
                if( odd_root == nullptr )
                {
                    odd_root = current;
                    odd_tail = current;
                }
                else
                {
                    odd_tail->setNext(current);
                    odd_tail = current;
                }
            }
            else
            {
                if( even_root == nullptr )
                {
                   even_root = current;
                   even_tail = current;
                }
                else
                {
                    even_tail->setNext(current);
                    even_tail = current;
                }
            }
            is_odd = ! is_odd;
            current = current->getNext();
        }
        root_node = odd_root;
        odd_tail->setNext(even_root);
        even_tail->setNext(nullptr);
        root_node->dumpNodes();
        
    }

}
