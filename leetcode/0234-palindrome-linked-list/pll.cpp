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
    bool first = true;
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( ! first )
            std::cout << "->" ;
        first = false;
        std::cout << curr->val ;
        curr = curr->next;
    }
    std::cout << std::endl;
}


ListNode *reverseList(ListNode *head)
{
    if(( head == nullptr ) || (head->next == nullptr))
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

bool isPalindrome(ListNode* head)
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return true;
    
    ListNode *slow;
    ListNode *fast;
    ListNode *prev;
    int flipper = 0;
    fast = head;
    slow = head;
    while( fast != nullptr )
    {
        if( flipper % 2 )
        {
            prev = slow;
            slow = slow->next;
        }
        fast = fast->next;
        flipper++;
    }
    prev->next = nullptr;
    ListNode *revs = reverseList( slow );
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( revs == nullptr )
            return false;
        if( curr->val != revs->val )
            return false;
        curr = curr->next;
        revs = revs->next;
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0234-palindrome-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *ttwo = new ListNode(2);
        ListNode *oone = new ListNode(1);

        one->next = two;
        two->next = ttwo;
        ttwo->next = oone; 
        bool expected = true;
        bool result = isPalindrome(one);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);

        one->next = two;
        bool expected = false;
        bool result = isPalindrome(one);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
