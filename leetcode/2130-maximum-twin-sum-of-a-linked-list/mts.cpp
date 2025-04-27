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
    ListNode *curr = head;
    while( curr != nullptr )
    {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode *reverseList(ListNode *head)
{
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


int pairSum(ListNode* head)
{
    // first find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;

    int flip = 0;
    while( fast != nullptr )
    {
        fast = fast->next;
        flip++;
        if( flip % 2 )
            slow = slow->next;
    }
    // slow is pointing to the middle of the list.  so reverse it.
    ListNode *curr = slow;

    ListNode *after = reverseList(curr);
    int max_sum = INT_MIN;
    while( after != nullptr )
    {
        int sum = after->val + head->val;
        max_sum = std::max( max_sum, sum );
        after = after->next;
        head = head->next;
    }
    
    return max_sum;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2130-maximum-twin-sum-of-a-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *five  = new ListNode(5);
        ListNode *four  = new ListNode(4);
        ListNode *two   = new ListNode(2);
        ListNode *one   = new ListNode(1);

        five->next  = four;
        four->next  = two;
        two->next   = one;
        
        int expected = 6;
        int result = pairSum(five);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        ListNode *five = new ListNode(5);
        ListNode *four = new ListNode(4);
        ListNode *two  = new ListNode(2);
        ListNode *one  = new ListNode(1);

        five->next = four;
        four->next = two;
        two->next  = one;
        
        int expected = 6;
        int result = pairSum(five);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        ListNode *four  = new ListNode(4);
        ListNode *two   = new ListNode(2);
        ListNode *ttwo  = new ListNode(2);
        ListNode *three = new ListNode(3);

        four->next = two;
        two->next  = ttwo;
        ttwo->next = three;
        
        int expected = 7;
        int result = pairSum(four);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        ListNode *one  = new ListNode(1);
        ListNode *two   = new ListNode(100000);

        one->next = two;
        
        int expected = 100001;
        int result = pairSum(one);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
