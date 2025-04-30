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


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

void dumpList(ListNode *list)
{
    ListNode *curr = list; 
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
    }
    std::cout << std::endl;
}



std::vector<int> monoLess(std::vector<int> nums)
{
    std::vector<int> lessers( nums.size(), -1 );
    std::stack<int>  mstack;

    for(int index =0;index<nums.size();index++)
    {
        while(( ! mstack.empty() ) && ( nums[ mstack.top() ] > nums[index] ))
        {
            mstack.pop();
        }
        if( ! mstack.empty() )
            lessers[index] = mstack.top() ;
        mstack.push(index);
    }
    return lessers;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "Alfonso's Programming Cheatsheet" << std::endl << std::endl;
    
    int test_case = 1;
    {
        std::vector<int> nums  = {5,7,8,2,4,6,11,2,3};
        std::vector<int> result   = monoLess(nums);
        std::cout << std::endl << "Recipe: " << test_case << " - Monotonic stack lessers" << std::endl;
        dumpValues(nums);
        dumpValues(result);
    }
    {
        std::cout << std::endl << "Recipe: " << test_case << " - Reverse Linked List" << std::endl;
        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *thr = new ListNode(3);
        ListNode *fou = new ListNode(4);
        ListNode *fiv = new ListNode(5);

        one->next = two;
        two->next = thr;
        thr->next = fou;
        fou->next = fiv;

        dumpList(one);
        ListNode *reversed = reverseList(one);
        dumpList(reversed);
    }
    return 0;
}
