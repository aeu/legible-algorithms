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
    bool first_time = true;
    while( curr != nullptr )
    {
        if( ! first_time )
        {
            std::cout << "->" ;
        }
        else
        {
            first_time = false;
        }
        std::cout << curr->val ;
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode *reverse(ListNode *head)
{
    if( ( head == nullptr ) || ( head->next == nullptr ))
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while( curr != nullptr )
    {
        ListNode *ntemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ntemp;
    }
    return prev;
    
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode *new_head = nullptr;
    ListNode *new_tail = nullptr;
    ListNode *safety;
    ListNode *curr = head;
    ListNode *khead;
    ListNode *ktail;
    
    curr = head;
    khead = head;
    while( curr != nullptr )
    {
        int steps = k;
        while(( curr != nullptr ) && ( steps > 0 ))
        {
            ktail = curr;
            curr = curr->next;
            steps--;
        }
        safety = ktail->next;
        ktail->next = nullptr;

        // only reverse the segment if there's actually k things in
        // it.
        if( steps == 0 )
        {
            ktail = khead;
            khead = reverse(khead);
        }
        
        if( new_head == nullptr )
        {
             new_head = khead;
        }
        if( new_tail != nullptr )
        {
             new_tail->next = khead;
        }
        new_tail = ktail;
        new_tail->next = nullptr;
        curr = safety;
        khead = safety;
    }

    return new_head;
    
}

int doWork()
{
    return 1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0025-reverse-nodes-in-k-group" << std::endl;
    int test_case = 1;
    {
        std::cout << std::endl << "Test Case : " << test_case++ << std::endl;
        ListNode *one    = new ListNode(1);
        ListNode *two    = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four   = new ListNode(4);
        ListNode *five   = new ListNode(5);
        // ListNode *six    = new ListNode(6);
        // ListNode *seven  = new ListNode(7);
        // ListNode *eight  = new ListNode(8);
        // ListNode *nine   = new ListNode(9);
        // ListNode *ten    = new ListNode(10);

        one->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        // five->next = six;
        // six->next = seven;
        // seven->next = eight;
        // eight->next = nine;
        // nine->next = ten;
        dumpList(one);
        ListNode *temp = reverseKGroup( one, 2 );
        dumpList(temp);
    }
    {
        std::cout << std::endl << "Test Case : " << test_case++ << std::endl;
        ListNode *one    = new ListNode(1);
        ListNode *two    = new ListNode(2);
        ListNode *three  = new ListNode(3);
        ListNode *four   = new ListNode(4);
        ListNode *five   = new ListNode(5);
        // ListNode *six    = new ListNode(6);
        // ListNode *seven  = new ListNode(7);
        // ListNode *eight  = new ListNode(8);
        // ListNode *nine   = new ListNode(9);
        // ListNode *ten    = new ListNode(10);

        one->next = two;
        two->next = three;
        three->next = four;
        four->next = five;
        // five->next = six;
        // six->next = seven;
        // seven->next = eight;
        // eight->next = nine;
        // nine->next = ten;
        dumpList(one);
        ListNode *temp = reverseKGroup( one, 3 );
        dumpList(temp);
    }
    return 0;
}
