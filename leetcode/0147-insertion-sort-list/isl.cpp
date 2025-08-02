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


void insertIntoList(ListNode *head, ListNode *candidate)
{
    if( head->next == nullptr )
    {
        head->next = candidate;
        candidate->next = nullptr;
        return;
    }


    ListNode *curr = head;
    ListNode *after = head->next;
    while( curr != nullptr )
    {
        after = curr->next;
        if(( after == nullptr) || ( candidate->val <= after->val ))
        {
            curr->next = candidate;
            candidate->next = after;
            break;
        }
        curr = after;
    }
}

ListNode* insertionSortList(ListNode* head) 
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return head;

    ListNode *dummy = new ListNode(0);

    ListNode *curr = head;
    ListNode *next = nullptr;
    while(curr != nullptr )
    {
        next = curr->next;
        insertIntoList( dummy, curr );
        curr = next;
    }
    ListNode *retval = dummy->next;
    delete dummy;
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0147-insertion-sort-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *fou = new ListNode(4);
        ListNode *two = new ListNode(2);
        ListNode *one = new ListNode(1);
        ListNode *thr = new ListNode(3);

        fou->next = two;
        two->next = one;
        one->next = thr;
        dumpList(fou);
        ListNode *sorted = insertionSortList(fou);
        dumpList(sorted);

        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *mon = new ListNode(-1);
        ListNode *fiv = new ListNode(5);
        ListNode *thr = new ListNode(3);
        ListNode *fou = new ListNode(4);
        ListNode *zer = new ListNode(0);

        mon->next = fiv;
        fiv->next = thr;
        thr->next = fou;
        fou->next = zer;

        dumpList(mon);
        ListNode *sorted = insertionSortList(mon);
        dumpList(sorted);

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
