// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
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


void dumpList(ListNode *list)
{
    ListNode *curr = list;
    ListNode *slow = list;
    int flipper = 0;
    
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( flipper % 2 )
        {
            slow = slow->next;
        }
        if( curr == slow )
        {
            std::cout << "endless loop, breaking" << std::endl;
            break;
        }
        flipper++;
    }
    std::cout << std::endl;
}

ListNode *detectCycle(ListNode *head)
{
    if( head == nullptr )
        return head;
    if( head->next == nullptr )
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    int flipper = 0;
    while( fast != nullptr )
    {
        if( flipper % 2 )
        {
            slow = slow->next;
        }
        fast = fast->next;
        if( slow == fast )
        {
            slow = head;
            while( slow != fast )
            {
                std::cout << "asdf" << std::endl;
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        flipper++;
    }
    return nullptr;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0142-linked-list-cycle-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *thr = new ListNode(3);
        ListNode *two = new ListNode(2);
        ListNode *zer = new ListNode(0);
        ListNode *mfo = new ListNode(-4);

        thr->next = two;
        two->next = zer;
        zer->next = mfo;
        mfo->next = two;
        
        dumpList(thr);
        ListNode *inter = detectCycle(thr);
        if( inter != nullptr )
            std::cout << "candidate : " << inter->val << std::endl;
        else
            std::cout << "no hit : " << inter->val << std::endl;
        
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);

        one->next = two;
        two->next = one;
        
        dumpList(one);
        ListNode *inter = detectCycle(one);
        if( inter != nullptr )
            std::cout << "candidate : " << inter->val << std::endl;
        else
            std::cout << "no hit : " << inter->val << std::endl;
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *one = new ListNode(1);

        dumpList(one);
        ListNode *inter = detectCycle(one);
        if( inter != nullptr )
            std::cout << "candidate : " << inter->val << std::endl;
        else
            std::cout << "no hit : " << inter->val << std::endl;
        
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
