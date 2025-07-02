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


ListNode *deleteDuplicates(ListNode *head)
{
    if( head == nullptr )
        return nullptr;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr;
    ListNode *insertion_point;

    insertion_point = dummy;
    curr = head;

    while( curr != nullptr )
    {
        // the next node is the same as the current one
        if(( curr->next != nullptr ) && ( curr->val == curr->next->val ))
        {
            // keep going until there next node is different (there
            // may be more than one dupe)
            while(( curr->next != nullptr ) && ( curr->next->val == curr->val ))
            {
                curr = curr->next;
            }
            insertion_point->next = curr->next;
        }
        // not a duplicate, so just advance the insertion point
        else
        {
            insertion_point = insertion_point->next;
        }
        curr = curr->next;
    }
    ListNode *new_head = dummy->next;
    delete dummy;
    return new_head;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0082 - Remove Duplicates from Sorted List II" << std::endl;
    {
        ListNode *fir  = new ListNode(1);
        ListNode *sec  = new ListNode(2);
        ListNode *thi  = new ListNode(3);
        ListNode *fou  = new ListNode(3);
        ListNode *fif  = new ListNode(4);
        ListNode *six  = new ListNode(4);
        ListNode *sev  = new ListNode(5);


        fir->next  = sec;
        sec->next  = thi;
        thi->next  = fou;
        fou->next  = fif;
        fif->next  = six;
        six->next  = sev;

        
        dumpNodes(fir);
        ListNode *new_head = deleteDuplicates(fir);
        dumpNodes(new_head);
        
    }
    {
        ListNode *fir  = new ListNode(1);
        ListNode *sec  = new ListNode(1);
        ListNode *thi  = new ListNode(1);
        ListNode *fou  = new ListNode(2);
        ListNode *fif  = new ListNode(3);


        fir->next  = sec;
        sec->next  = thi;
        thi->next  = fou;
        fou->next  = fif;

        
        dumpNodes(fir);
        ListNode *new_head = deleteDuplicates(fir);
        dumpNodes(new_head);
        
    }
    {
        ListNode *fir  = new ListNode(1);
        ListNode *sec  = new ListNode(2);
        ListNode *thi  = new ListNode(2);


        fir->next  = sec;
        sec->next  = thi;

        
        dumpNodes(fir);
        ListNode *new_head = deleteDuplicates(fir);
        dumpNodes(new_head);
        
    }
}
