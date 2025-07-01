// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void dumpNodes(ListNode *head)
{
    ListNode *current = head;
    bool first_time = true;
    while( current != nullptr )
    {
        if( ! first_time )
            std::cout << " -> ";
        std::cout << current->val;
        first_time = false;
        current = current->next;
    }
    std::cout << std::endl;
}

// create two pointsers, a lead and a follow and have them advance
// down the linked list.  only increment the follow pointer after the
// lead one has gone N steps.  then when the lead one gets to the end,
// the follow one will be at the Nth from the end.  By also tracking
// the previous list element to it, we can now delete the Nth element.

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *lead = head;
    ListNode *follow = head;
    ListNode *previous = dummy;
    int steps = 0;
    while( lead != nullptr )
    {
        lead = lead->next;
        steps++;
        if( steps > n )
        {
            follow = follow->next;
            previous = previous->next;
        }
    }
    previous->next = follow->next;
    return dummy->next;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0019 - Remove Nth Node From End of List" << std::endl;
    {
        ListNode *head = new ListNode(1);
        ListNode *two  = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four  = new ListNode(4);
        ListNode *five  = new ListNode(5);

        head->next = two;
        two->next  = three;
        three->next = four;
        four->next = five;
        
        dumpNodes(head);
        ListNode *new_head = removeNthFromEnd(head,2);
        dumpNodes(new_head);
        
    }
    {
        ListNode *head = new ListNode(1);
        ListNode *two  = new ListNode(2);

        head->next = two;
        
        dumpNodes(head);
        ListNode *new_head = removeNthFromEnd(head,1);
        dumpNodes(new_head);
        
    }
}
