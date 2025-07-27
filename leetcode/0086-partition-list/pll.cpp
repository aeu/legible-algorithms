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


ListNode* partition(ListNode* head, int x) 
{
    if( ( head == nullptr ) || ( head->next == nullptr ))
        return head;

    ListNode *before = new ListNode(0);
    ListNode *after  = new ListNode(0);
    ListNode *btail = before;
    ListNode *atail = after;
    
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( curr->val < x )
        {
            btail->next = curr;
            btail = curr;
        }
        else
        {
            atail->next = curr;
            atail = curr;
        }
        curr = curr->next;
    }
    btail->next = after->next;
    atail->next = nullptr;
    ListNode *ret = before->next;
    delete before;
    delete after;
    return ret;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0086-partition-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one = new ListNode(1);
        ListNode *fou = new ListNode(4);
        ListNode *thr = new ListNode(3);
        ListNode *two = new ListNode(2);
        ListNode *fiv = new ListNode(5);
        ListNode *twt = new ListNode(2);

        one->next = fou;
        fou->next = thr;
        thr->next = two;
        two->next = fiv;
        fiv->next = twt;
        int x = 3;

        dumpList( one );
        ListNode *after = partition(one,x);
        dumpList(after);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *two = new ListNode(2);
        ListNode *one = new ListNode(1);

        two->next = one;
        int x = 2;

        dumpList( two );
        ListNode *after = partition(two,x);
        dumpList(after);
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
