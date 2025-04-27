// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* swapPairs(ListNode* head)
{
    ListNode *newhead = nullptr;
    ListNode *newtail = nullptr;
    ListNode *curr = head;

    while( curr != nullptr )
    {
        ListNode *next = nullptr;
        ListNode *after = nullptr;
        ListNode *ntemp = nullptr;

        if( curr->next )
        {
            next = curr->next;
            after = curr;
            ntemp = next->next;
        }
        else
        {
            next = curr;
            after = nullptr;
            ntemp = nullptr;
        }
        if( newhead == nullptr )
        {
            newhead = next;
            newhead->next = after;
            newtail = after; 
        }
        else
        {
            newtail->next = next;
            newtail = next;
            if( next != nullptr )
            {
                next->next = after;
                newtail = after;
            }
        }
        if( newtail )
            newtail->next = nullptr;
        curr = ntemp;
    }
    return newhead;
}

void dumpList(ListNode *head)
{
    bool first = true;
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( ! first )
            std::cout << "->";
        std::cout << curr->val;
        first = false;
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0024-swap-nodes-in-pairs/" << std::endl << std::endl;
    int test_case = 1;
    {

        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *thr = new ListNode(3);
        ListNode *fou = new ListNode(4);

        one->next = two;
        two->next = thr;
        thr->next = fou;
        
        dumpList(one);
        ListNode *retval = swapPairs(one);
        dumpList(retval);
        
        bool expected = true;
        bool result = true;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
