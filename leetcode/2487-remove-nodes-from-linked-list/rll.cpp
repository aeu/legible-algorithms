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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x ) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void dumpVector(std::vector<int> nums)
{
    std::cout << "[" ;
    bool first = true;
    int index = 0;
    for(const auto curr : nums )
    {
        if( ! first )
            std::cout << ", " ;
        first = false;
        std::cout << index++ << ":" << curr;
    }
    std::cout << "]" << std::endl;
}

void testRemoveNodes(std::vector<int> nums)
{
    std::vector<int> greaters( nums.size(), -1 );
    dumpVector(nums);

    std::stack<int> gstack;
    for(int index=nums.size()-1;index>=0;index--)
    {
        while(( ! gstack.empty() ) && ( nums[gstack.top()] <= nums[index]))
        {
            gstack.pop();
        }

        if( ! gstack.empty() )
            greaters[index] = gstack.top();

        gstack.push(index);
    }
    dumpVector(greaters);
}


void dumpList(ListNode *list)
{
    ListNode *curr = list;
    ListNode *original = list;
    ListNode *slow = list;
    int flipper = 0;
    
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( flipper % 2 )
        {
            slow = slow->next;
        }
        if( curr == slow )
        {
            std::cout << "endless loop, breaking" << std::endl;
            break;
        }
        flipper++;
    }
    std::cout << std::endl;
}


ListNode *removeNodes(ListNode *head)
{
    std::vector<int> nums;
    ListNode *curr = head;
    while( curr )
    {
        nums.push_back(curr->val);
        curr = curr->next;
    }
    std::vector<int> greaters( nums.size(), -1 );
    std::stack<int> gstack;
    for(int index=nums.size()-1;index>=0;index--)
    {
        while(( ! gstack.empty() ) && ( nums[gstack.top()] <= nums[index]))
        {
            gstack.pop();
        }

        if( ! gstack.empty() )
            greaters[index] = gstack.top();

        gstack.push(index);
    }

    ListNode *nroot = new ListNode(0,head);
    ListNode *prev = nroot;
    curr = head;
    for(int index=0;index<greaters.size();index++)
    {
        // there's a greater node subsequent to what we are currently at.
        if( greaters[index] != -1 )
        {
            // skip us
            prev->next = curr->next;
        }
        else
        {
            prev = prev->next;
        }
        curr = curr->next;
    }
    return nroot->next;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "2487-remove-nodes-from-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *five = new ListNode(5);
        ListNode *two = new ListNode(2);
        ListNode *thir = new ListNode(13);
        ListNode *thr = new ListNode(3);
        ListNode *eigh = new ListNode(8);

        five->next = two;
        two->next = thir;
        thir->next = thr;
        thr->next = eigh;

        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << std::endl;
        dumpList(five);
        ListNode *newlist = removeNodes(five);
        dumpList(newlist);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *five = new ListNode(1);
        ListNode *two = new ListNode(1);
        ListNode *thir = new ListNode(1);
        ListNode *thr = new ListNode(1);

        five->next = two;
        two->next = thir;
        thir->next = thr;

        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << std::endl;
        dumpList(five);
        ListNode *newlist = removeNodes(five);
        dumpList(newlist);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
