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
        return;
    ListNode *curr = head;
    while( curr != nullptr )
    {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << std::endl;
}


ListNode* reverseList(ListNode* head)
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return head;
    
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while( curr != nullptr )
    {
        ListNode *ntemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ntemp;
    }
    return prev;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0206-reverse-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one   = new ListNode(1);
        ListNode *two   = new ListNode(2);
        ListNode *three = new ListNode(3);
        ListNode *four  = new ListNode(4);
        ListNode *five  = new ListNode(5);
        ListNode *six  = new ListNode(6);

        one->next   = two;
        two->next   = three;
        three->next = four;
        four->next  = five;
        five->next  = six;

        dumpList(one);
        ListNode *reversed = reverseList(one);
        dumpList(reversed);
        
        std::cout << std::endl;
        //        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
