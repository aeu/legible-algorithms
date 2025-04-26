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

void dumpList(ListNode *head)
{
    if( head == nullptr )
        std::cout << "nullhead" << std::endl;
    ListNode *curr = head;
    while( curr != nullptr )
    {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << std::endl;
}



ListNode* oddEvenList(ListNode* head)
{
    ListNode *odd_head = nullptr; // head;
    ListNode *odd_tail = nullptr;
    ListNode *even_head = nullptr;
    ListNode *even_tail = nullptr;

    int step = 0;

    if( head == nullptr )
        return nullptr;
    
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( ! ( step % 2 ))
        {
            if( odd_head == nullptr )
            {
                odd_head = curr;
                odd_tail = curr;
            }
            else
            {
                odd_tail->next = curr;
                odd_tail = curr;
            }
        }
        else
        {
            if( even_head == nullptr )
            {
                even_head = curr;
                even_tail = curr;
            }
            else
            {
                even_tail->next = curr;
                even_tail = curr;
            }
        }
        step++;
        curr = curr->next;
    }
    if( even_tail )
        even_tail->next = nullptr;

    odd_tail->next = even_head;
    return odd_head;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0328-odd-even-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one    = new ListNode(1);
        ListNode *two    = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four   = new ListNode(4);
        ListNode *five   = new ListNode(5);

        one->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        dumpList(one);
        ListNode *after = oddEvenList(one);
        dumpList(after);

        std::cout << std::endl;
    }
    {
        ListNode *one    = new ListNode(1);
        ListNode *two    = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four   = new ListNode(4);
        ListNode *five   = new ListNode(5);
        ListNode *six    = new ListNode(6);
        ListNode *seven  = new ListNode(7);

        two->next = one;
        one->next = three;
        three->next = five;
        five->next = six;
        six->next = four;
        four->next = seven;

        dumpList(two);
        ListNode *after = oddEvenList(two);
        dumpList(after);

        std::cout << std::endl;
    }
    return 0;
}
