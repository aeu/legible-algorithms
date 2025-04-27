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

int doWork()
{
    return 1;
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
bool hasCycle(ListNode *head)
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return false;

    ListNode *slow = head;
    ListNode *fast = head;
    int flipper = 0;

    while( fast != nullptr )
    {
        fast = fast->next;
        if( flipper % 2 )
        {
            slow = slow->next;
        }
        if( slow == fast )
            return true;
        flipper++;
    }
    return false;
}
    
int main(int argc, char **argv)
{
    std::cout << std::endl << "0141-linked-list-cycle" << std::endl << std::endl;
    int test_case = 1;
    {

        ListNode *three = new ListNode(3);
        ListNode *two = new ListNode(2);
        ListNode *zero = new ListNode(0);
        ListNode *min_four = new ListNode(-4);

        three->next = two;
        two->next = zero;
        zero->next = min_four;
        min_four->next = two;

        bool expected = true;
        bool result = hasCycle(three);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {

        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);

        one->next = two;
        two->next = one;

        bool expected = true;
        bool result = hasCycle(one);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
