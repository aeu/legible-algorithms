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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void dumpList(ListNode *list)
{
    ListNode *curr = list;
    ListNode *original = list;
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( curr == original )
        {
            std::cout << "endless loop, breaking" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}


ListNode * buildList(std::vector<int> values )
{
    ListNode * prev_node;
    ListNode * next_node;
    ListNode * root_node;
    bool first_time = true;

    for(int current : values )
    {
        if( first_time )
        {
            root_node = new ListNode(current);
            prev_node = root_node;
            first_time = false;
        }
        else
        {
            next_node = new ListNode(current);
            prev_node->next = next_node;
            prev_node = next_node;
        }
    }
    return root_node;
}
#if 0
ListNode* deleteMiddle(ListNode* root_node)
{
    // work
    ListNode * lead_node;
    ListNode * trail_node;
    ListNode * trail_nodes_parent;
    
    lead_node = root_node;
    trail_node = root_node;
    trail_nodes_parent = root_node;
    
    int loop_count = 0;
    while( lead_node->next )
    {
        if( loop_count & 1 )
        {
            trail_nodes_parent = trail_node;
            trail_node = trail_node->next;
        }
        lead_node = lead_node->next;
        loop_count++;
    }
    if( loop_count == 1 )
        trail_node = root_node->next;
    
    trail_nodes_parent->next = trail_node->next;
    return root_node;
}
#endif

ListNode* deleteMiddle(ListNode* root_node)
{
    if(( root_node == nullptr ) || ( root_node->next == nullptr ))
        return nullptr;
    // work
    ListNode * lead_node;
    ListNode * trail_node;
    ListNode * trail_nodes_parent;
    
    lead_node = root_node;
    trail_node = root_node;
    trail_nodes_parent = root_node;
    
    int loop_count = 0;
    while( lead_node )
    {
        if( loop_count & 1 )
        {
            trail_nodes_parent = trail_node;
            trail_node = trail_node->next;
        }
        lead_node = lead_node->next;
        loop_count++;
    }
    if( trail_node->next != nullptr )
    {
        trail_nodes_parent->next = trail_node->next;
    }
    else
    {
        trail_nodes_parent->next = nullptr;
    }
    return root_node;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<int> values = { 1,3,4,7,1,2,6 };
        ListNode * root_node = buildList(values);
        std::cout << std::endl;
        bool expected = true;
        bool result = true;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        dumpList(root_node);
        deleteMiddle(root_node);
        dumpList(root_node);
    }
    {
        std::vector<int> values = { 1,2,3,4 };
        ListNode * root_node = buildList(values);
        bool expected = true;
        bool result = true;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        dumpList(root_node);
        deleteMiddle(root_node);
        dumpList(root_node);
    }
    {
        std::vector<int> values = { 2,1 };
        ListNode * root_node = buildList(values);
        bool expected = true;
        bool result = true;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        dumpList(root_node);
        deleteMiddle(root_node);
        dumpList(root_node);
    }
}
