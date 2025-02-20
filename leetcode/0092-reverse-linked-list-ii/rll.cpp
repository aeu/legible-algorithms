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
    while( current != nullptr )
    {
        std::cout << current->val ;
        if( current->next != nullptr )
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

ListNode* reverse(ListNode* head)
{
    if(head == nullptr )
        return nullptr;

    // 1 2 3 4 5 6 7 8 9 10

    ListNode *current;
    ListNode *old_head;
    ListNode *new_head;
    ListNode *after;

    new_head = head;       // 1
    old_head = head;       // 1
    current  = head->next; // 2
    old_head->next = nullptr;
    std::cout << "before while" << std::endl;
    while( current != nullptr )
    {
        std::cout << "in while" << std::endl;
        after = current->next; // 3
        old_head = new_head;
        new_head = current;    // 2
        new_head->next = old_head; // 1
        current = after;        // 3
    }
    return new_head;
    
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0092 - Reverse Linked List II" << std::endl;
    {
        ListNode *head = new ListNode(1);
        ListNode *two  = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four  = new ListNode(4);
        ListNode *five  = new ListNode(5);
        ListNode *six  = new ListNode(6);
        ListNode *seven  = new ListNode(7);
         ListNode *eight  = new ListNode(8);
         ListNode *nine  = new ListNode(9);
         ListNode *ten  = new ListNode(10);

        head->next = two;
        two->next  = three;
        three->next = four;
        four->next = five;
        five->next = six;
        six->next = seven;
        seven->next = eight;
        eight->next = nine;
        nine->next = ten;
        
        dumpNodes(head);
        ListNode *new_head = reverse(head);
        dumpNodes(new_head);
        
        //        ListNode *new_head = reverseBetween(head,3,5);
    }
}
