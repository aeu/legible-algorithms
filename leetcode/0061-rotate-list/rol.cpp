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
#include <queue>

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

ListNode* rotateRight(ListNode* head, int k)
{
    if(( head == nullptr ) || ( head->next == nullptr ) || ( k == 0 )) 
        return head;
    int length = 1;
    ListNode *curr = head->next;
    ListNode *prev = head;
    ListNode *tail = nullptr;
    while( curr != nullptr )
    {
        length++;
        curr = curr->next;
        prev = prev->next;
    }

    if( k == length )
        return head;

    if ( k > length )
        k = k % length;

    int tails_position = length - k - 1 ;

    tail = prev;
    tail->next = head;

    ListNode *new_tail = head;
    for(int index = 0 ; index < tails_position; ++index )
    {
        new_tail = new_tail->next;
    }
    ListNode *new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0061 - Rotate List" << std::endl;
    {
        ListNode *fir  = new ListNode(1);
        ListNode *sec  = new ListNode(2);

        fir->next  = sec;
        dumpNodes(fir);
        ListNode *new_head = rotateRight(fir, 1);
        dumpNodes(new_head);
    }
    {
        ListNode *fir  = new ListNode(1);
        ListNode *sec  = new ListNode(2);
        ListNode *thi  = new ListNode(3);
        ListNode *fou  = new ListNode(4);
        ListNode *fif  = new ListNode(5);


        fir->next  = sec;
        sec->next  = thi;
        thi->next  = fou;
        fou->next  = fif;
        dumpNodes(fir);
        ListNode *new_head = rotateRight(fir, 2);
        dumpNodes(new_head);
    }
}
