// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if( list1 == nullptr )
        return list2;
    if( list2 == nullptr )
        return list1;
    
    
    ListNode *head;
    ListNode *left = list1;
    ListNode *right = list2;
    ListNode *current_node;
    ListNode *tail;

    if( left->val <= right->val )
    {
        head = left;
        tail = head;
        left = left->next;
    }
    else
    {
        head = right;
        tail = head;
        right = right->next;
    }
    
    while( ( left != nullptr ) && ( right != nullptr ))
    {
        if( left->val <= right->val )
        {
            tail->next = left;
            current_node = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            current_node = right;
            right = right->next;
        }
        tail = current_node; 
    }

    while( left != nullptr )
    {
        tail->next = left;
        tail = left;
        left = left->next;
    }
    while( right != nullptr )
    {
        tail->next = right;
        tail = right;
        right = right->next;
    }
    
    return head;
}

int main( int argc, char **argv)
{
    printf("Leetcode #0021 - Merge Two Sorted Lists\n");
    {
    }
    return 0;
}
