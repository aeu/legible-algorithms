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
    ListNode *original = list;
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( curr == original )
        {
            std::cout << "endless loop, breaking" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

 ListNode* deleteDuplicates(ListNode* head) 
 {
    if(( head == nullptr)||(head->next == nullptr))
        return head;

    ListNode *lead = head->next;       
    ListNode *follow = head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    while( lead != nullptr )
    {
        if( lead->val != follow->val )
        {
            follow->next = lead;
            follow = lead;
        }
        lead = lead->next;
    }
    follow->next = nullptr;
    return dummy->next;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0083-remove-duplicates-from-sorted-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one = new ListNode(1);
        ListNode *oone = new ListNode(1);
        ListNode *two = new ListNode(2);

        one->next = oone;
        oone->next = two;

        dumpList(one);
        ListNode *removed = deleteDuplicates(one);
        dumpList(removed);
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
        ListNode *oone = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *thr = new ListNode(3);
        ListNode *thr2 = new ListNode(3);

        one->next = oone;
        oone->next = two;
        two->next = thr;
        thr->next = thr2;

        dumpList(one);
        ListNode *removed = deleteDuplicates(one);
        dumpList(removed);
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
