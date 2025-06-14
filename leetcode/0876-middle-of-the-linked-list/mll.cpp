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

ListNode* middleNode(ListNode* head)
{
    if( ( head == nullptr ) || ( head->next == nullptr ))
        return head;
    ListNode *curr = head;
    ListNode *trail = head;
    int count = 0;
    while( curr != nullptr )
    {
        if( count % 2 )
        {
            trail = trail->next;
        }
        curr = curr->next;
        count++;
    }
    if( ! ( count % 2 ))
        trail = trail->next;
    return trail;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0876-middle-of-the-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
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
