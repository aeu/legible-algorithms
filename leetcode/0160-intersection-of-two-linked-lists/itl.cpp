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


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *aptr = headA;
    ListNode *bptr = headB;
    if( headA == nullptr )
        return nullptr;
    if( headB == nullptr )
        return nullptr;
    while( aptr != bptr )
    {
        if( aptr )
            aptr = aptr->next;
        else
            aptr = headB;

        if( bptr )
            bptr = bptr->next;
        else
            bptr = headA;
    }
    return aptr;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0160-intersection-of-two-linked-lists" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *a1 = new ListNode(0);
        ListNode *a2 = new ListNode(0);
        ListNode *b1 = new ListNode(0);
        ListNode *b2 = new ListNode(0);
        ListNode *b3 = new ListNode(0);
        ListNode *c1 = new ListNode(1);
        ListNode *c2 = new ListNode(0);
        ListNode *c3 = new ListNode(0);

        a1->next = a2;
        a2->next = c1;
        c1->next = c2;
        c2->next = c3;

        b1->next = b2;
        b2->next = b3;
        b3->next = c1;

        ListNode *expected = c1;
        ListNode *result = getIntersectionNode(a1,b1);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
