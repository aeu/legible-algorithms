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
        std::vector<int> values = { 1,3,4,7,1,2,6 };
        std::shared_ptr<ListNode> root_node = buildList(values);
        
        root_node->dumpNodes();

        // work
        std::shared_ptr<ListNode> lead_node;
        std::shared_ptr<ListNode> trail_node;
        std::shared_ptr<ListNode> trail_nodes_parent;

        lead_node = root_node;
        trail_node = root_node;
        trail_nodes_parent = root_node;

        int loop_count = 0;
        while( lead_node->getNext() )
        {
            if( loop_count & 1 )
            {
                trail_nodes_parent = trail_node;
                trail_node = trail_node->getNext();
            }
            lead_node = lead_node->getNext();
            loop_count++;
        }
        if( loop_count == 1 )
            trail_node = root_node->getNext();
        //        std::cout << "at end, lead node : " << lead_node->getValue() << std::endl;
        // std::cout << "at end, trail node : " << trail_node->getValue() << std::endl;
        //std::cout << "at end, trail parent : " << trail_nodes_parent->getValue() << std::endl;

        trail_nodes_parent->setNext( trail_node->getNext() );
        root_node->dumpNodes();
    }
    {
        std::vector<int> values = { 1,2,3,4 };
        std::shared_ptr<ListNode> root_node = buildList(values);

        // work
        std::shared_ptr<ListNode> lead_node;
        std::shared_ptr<ListNode> trail_node;
        std::shared_ptr<ListNode> trail_nodes_parent;

        lead_node = root_node;
        trail_node = root_node;
        trail_nodes_parent = root_node;

        int loop_count = 0;
        while( lead_node->getNext() )
        {
            if( loop_count & 1 )
            {
                trail_nodes_parent = trail_node;
                trail_node = trail_node->getNext();
            }
            lead_node = lead_node->getNext();
            loop_count++;
        }
        if( loop_count == 1 )
            trail_node = root_node->getNext();
        //        std::cout << "at end, lead node : " << lead_node->getValue() << std::endl;
        // std::cout << "at end, trail node : " << trail_node->getValue() << std::endl;
        //std::cout << "at end, trail parent : " << trail_nodes_parent->getValue() << std::endl;

        trail_nodes_parent->setNext( trail_node->getNext() );
        root_node->dumpNodes();
    }
    {
        std::vector<int> values = { 2,1 };
        std::shared_ptr<ListNode> root_node = buildList(values);
        root_node->dumpNodes();

        // work
        std::shared_ptr<ListNode> lead_node;
        std::shared_ptr<ListNode> trail_node;
        std::shared_ptr<ListNode> trail_nodes_parent;

        lead_node = root_node;
        trail_node = root_node;
        trail_nodes_parent = root_node;

        int loop_count = 0;
        while( lead_node->getNext() )
        {
            if( loop_count & 1 )
            {
                trail_nodes_parent = trail_node;
                trail_node = trail_node->getNext();
            }
            lead_node = lead_node->getNext();
            loop_count++;
        }
        if( loop_count == 1 )
            trail_node = root_node->getNext();

        trail_nodes_parent->setNext( trail_node->getNext() );
        root_node->dumpNodes();
    }
}
