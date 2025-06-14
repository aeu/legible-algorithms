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
    ListNode() : val(0), next(nullptr){}
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



ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    
    int running_sum = 0;
    std::unordered_map<int,ListNode *> prefixes;

    ListNode *curr = dummy;
    while( curr != nullptr )
    {
        running_sum += curr->val;
        prefixes[running_sum] = curr;
        curr = curr->next;
    }

    curr = dummy;
    running_sum = 0;
    while( curr != nullptr )
    {
        running_sum += curr->val;
        curr->next = prefixes[running_sum]->next;
        curr = curr->next;
    }
    
    return dummy->next;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1171-remove-zero-sum-consecutive-nodes-from-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one    = new ListNode(1);
        ListNode *two    = new ListNode(2);
        ListNode *min3   = new ListNode(-3);
        ListNode *three  = new ListNode(3);
        ListNode *onee   = new ListNode(1);

        one->next = two;
        two->next = min3;
        min3->next = three;
        three->next = onee;
        ListNode *head = one;
        dumpList(head);
        ListNode *nhead = removeZeroSumSublists(head);
        dumpList(nhead);

        bool expected = true;
        bool result = true;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
