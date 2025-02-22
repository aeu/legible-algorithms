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



ListNode* deleteDuplicates(ListNode* head)
{
    if( head == nullptr )
        return nullptr;

    if( head->next == nullptr )
        return head;

    if(( head->val == head->next->val )
       && ( head->next->next == nullptr ))
        return nullptr;

    
    ListNode *dummy = new ListNode(0);
    std::map<int,int> skips;
    
    ListNode *lead;
    ListNode *prev;
    ListNode *tail;

    prev = head;
    lead = head->next;
    tail = dummy;
    tail->next = nullptr;

    while( lead != nullptr )
    {
        if( lead->val == prev->val )
        {
            skips[ lead->val ] = 1;
            // std::cout << "adding " << prev->val << std::endl;
            //            skips.push_back( lead->val );
        }
        if( skips.empty() )
        {
            tail->next = prev;
            tail = tail->next;
        }
        else
        {
            if( skips.find( prev->val ) == skips.end() )
            {
                tail->next = prev;
                tail = tail->next;
            }
            if( prev->val > skips.begin()->first )
            {
                // std::cout << "removig " << prev->val << std::endl;
                skips.erase( skips.begin() );
            }
        }
        lead = lead->next;
        prev = prev->next;
    }
    // std::cout << "end of loop" << std::endl;
    // std::cout << tail->val << " <-- tail val " << std::endl;
    // std::cout << prev->val << " <-- prev val " << std::endl;
    if( skips.find( prev->val ) == skips.end() )
    {
        // std::cout << prev->val << " the final value was not in the skips table" << std::endl;
        tail->next = prev;
        tail = tail->next;
    }
    tail->next = nullptr;
    return dummy->next;
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
