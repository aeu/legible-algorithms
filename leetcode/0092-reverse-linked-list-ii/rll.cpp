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

ListNode* reverseBetween(ListNode* head, int left, int right)
{
     if ( head == nullptr )
        return nullptr;

    ListNode *left_node  = nullptr;
    ListNode *right_node = nullptr;

    ListNode *left_head  = nullptr;
    ListNode *left_tail  = nullptr;
    
    ListNode *prior_left = nullptr;
    ListNode *current = head;
    while( left_head == nullptr )
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
            left_node = current;
            left_head = current;
            left_tail = current;
            break;
        }
        current = current->next;
    }

    std::cout << "last before left " << prior_left->val << std::endl;
    std::cout << "Left Head " << left_head->val << std::endl;
    std::cout << "Left Tail " << left_tail->val << std::endl;
    //   H    PL   L             R  
    //   1 -> 2 -> 3 ->  4    -> 5 -> 6-> 7 -> 8-> x->
    ListNode *temp;
    current = left_node;
    while( right_node == nullptr )
    {
        left_head = current->next;
        temp = left_head->next;
        left_head->next = current;
        current = temp;
    }
    prior_left->next = left_head;
    left_tail->next = right_node;
    dumpNodes( head );

    return left_head;
}

ListNode* reverse(ListNode* head)
{
    if(head == nullptr )
        return nullptr;

    ListNode *temp;
    ListNode *current;
    ListNode *new_head;
    ListNode *previous;

    // 1 2 3 4 5 6 7 8 9 10
    
    previous = head;
    current = previous->next;
    while( current != nullptr )
    {
        temp = current->next;
        new_head = current;
        new_head->next = previous;
        previous = current;
        current = temp;
    }
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

        //        ListNode *new_head = reverseBetween(head,3,5);
    }
}
