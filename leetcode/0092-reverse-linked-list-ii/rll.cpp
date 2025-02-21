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

    new_head = head;
    old_head = head;
    current  = head->next;
    old_head->next = nullptr;
    while( current != nullptr )
    {
        after = current->next;
        old_head = new_head;
        new_head = current;
        new_head->next = old_head;
        current = after;
    }
    return new_head;
    
}


ListNode* reverseBetweenByValue(ListNode* head, int left, int right)
{
    if ( head == nullptr )
        return nullptr;

    if( left == right )
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode *left_head  = nullptr;
    ListNode *left_tail  = nullptr;
    
    ListNode *prior_left = nullptr;
    ListNode *current = head;
    while( current != nullptr )
    {
        if( current->next != nullptr )
        {
            if( current->next->val == left )
            {
                prior_left = current;
            }
        }
        if( current->val == left )
        {
            left_head = current;
            left_tail = current;
            break;
        }
        current = current->next;
    }
    if( left_head == nullptr )
        return dummy->next;

    ListNode *after;
    ListNode *old_head;
    current = left_head->next;  // 4

    while( current != nullptr )
    {
        after = current->next;      // 5
        old_head = left_head;
        left_head = current;        // 4
        left_head->next = old_head; // 3
        current = after;            // 5
        if( left_head->val == right )
            break;
    }
    prior_left->next = left_head;
    left_tail->next = current;
    return dummy->next;
}



ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if ( head == nullptr )
        return nullptr;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prior_left = dummy;
    ListNode *left_head  = head;
    ListNode *current = head;
    ListNode *left_tail  = nullptr;
    int node_count = 1;
    while( current != nullptr )
    {
        if( node_count == left  )
        {
            left_head = current;
            left_tail = current;
            break;
        }
        prior_left = current;
        current = current->next;
        node_count++;
    }

    ListNode *after;
    ListNode *old_head;

    while( current != nullptr )
    {
        after = current->next;      // 13
        old_head = left_head;       // 12
        left_head = current;        // 12
        left_head->next = old_head; // 12
        current = after;            // 13
        node_count++;               //  3
        if( node_count > right )
            break;
    }
    prior_left->next = left_head;
    left_tail->next = current;
    return dummy->next;
}



int main(int argc, char **argv)
{
    {
        ListNode *head = new ListNode(11);
        ListNode *two  = new ListNode(12);
        ListNode *three  = new ListNode(13);
        ListNode *four  = new ListNode(14);
        ListNode *five  = new ListNode(15);

        head->next = two;
        two->next  = three;
        three->next = four;
        four->next = five;
        
        dumpNodes(head);
        //    ListNode *new_head = reverse(head);
        //  dumpNodes(new_head);
        
        ListNode *new_head = reverseBetween(head,2,4);
        dumpNodes(new_head);
    }
    std::cout << "Leetcode 0092 - Reverse Linked List II" << std::endl;
    {
        ListNode *head = new ListNode(3);
        ListNode *two  = new ListNode(5);

        head->next = two;
        
        dumpNodes(head);
        ListNode *new_head = reverseBetween(head,1,2);
        dumpNodes(new_head);
    }
    {
        ListNode *head = new ListNode(5);
        dumpNodes(head);
        ListNode *new_head = reverseBetweenByValue(head,1,1);
        dumpNodes(new_head);
    }
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
        // ListNode *new_head = reverse(head);
        // dumpNodes(new_head);
        
        ListNode *new_head = reverseBetweenByValue(head,3,7);
        dumpNodes(new_head);
    }
}
