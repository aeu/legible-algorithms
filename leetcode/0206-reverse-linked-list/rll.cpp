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
    std::shared_ptr<ListNode> prev_node = nullptr;
    std::shared_ptr<ListNode> next_node = nullptr;
    std::shared_ptr<ListNode> root_node = nullptr;
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
        std::vector<int> values = { 1,2,3,4,5};
        std::shared_ptr<ListNode> root_node = buildList(values);
        root_node->dumpNodes();
        std::shared_ptr<ListNode> current;
        std::shared_ptr<ListNode> reversed_root;
        std::shared_ptr<ListNode> reversed_tail;
        std::shared_ptr<ListNode> temp;
        bool first_time = true;
        current = root_node;
        while( current != nullptr )
        {
            if( first_time )
            {
                reversed_root = current;
                reversed_tail = current;
                first_time = false;
            }
            temp = current->getNext();
            current->setNext(reversed_root);
            reversed_root = current;
            current = temp;
        }
        reversed_tail->setNext(nullptr);
        reversed_root->dumpNodes();
    }
    {
        std::vector<int> values = { 1,2 };
        std::shared_ptr<ListNode> root_node = buildList(values);
        if( root_node )
            root_node->dumpNodes();
        else
            std::cout << "[]" << std::endl;
        std::shared_ptr<ListNode> current;
        std::shared_ptr<ListNode> reversed_root;
        std::shared_ptr<ListNode> reversed_tail;
        std::shared_ptr<ListNode> temp;
        bool first_time = true;
        current = root_node;
        while( current != nullptr )
        {
            if( first_time )
            {
                reversed_root = current;
                reversed_tail = current;
                first_time = false;
            }
            temp = current->getNext();
            current->setNext(reversed_root);
            reversed_root = current;
            current = temp;
        }
        reversed_tail->setNext(nullptr);
        reversed_root->dumpNodes();
    }
    {
        std::vector<int> values = { };
        std::shared_ptr<ListNode> root_node = buildList(values);
        if( root_node )
            root_node->dumpNodes();
        else
            std::cout << "[]" << std::endl;
        std::shared_ptr<ListNode> current = nullptr;
        std::shared_ptr<ListNode> reversed_root = nullptr;
        std::shared_ptr<ListNode> reversed_tail = nullptr;
        std::shared_ptr<ListNode> temp = nullptr;
        bool first_time = true;
        current = root_node;
        while( current != nullptr )
        {
            if( first_time )
            {
                reversed_root = current;
                reversed_tail = current;
                first_time = false;
            }
            temp = current->getNext();
            current->setNext(reversed_root);
            reversed_root = current;
            current = temp;
        }
        if( reversed_tail )
        {
            reversed_tail->setNext(nullptr);
            reversed_root->dumpNodes();
        }
        else
        {
            std::cout << "[]" << std::endl;
        }            
    }
}
