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


std::vector<int> nextLargerNodes(ListNode* head)
{
    if(( head == nullptr ) || (head->next == nullptr ))
    {
        std::vector<int> greaters;
        greaters.push_back(0);
        return greaters;
    }
    std::vector<int> values;
    ListNode *curr = head;
    while( curr )
    {
        values.push_back(curr->val);
        curr = curr->next;
    }
    std::vector<int> greaters(values.size(),0);
    std::stack<int> index_mstack;
    for(int index=0;index<values.size();index++)
    {
        while( ! index_mstack.empty() &&
               values[index] > values[index_mstack.top()])
        {
            int old = index_mstack.top();
            index_mstack.pop();
            greaters[old] = values[index];
        }
        index_mstack.push(index);
    }
    return greaters;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1019-next-greater-node-in-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *two = new ListNode(2);
        ListNode *one = new ListNode(1);
        ListNode *fiv = new ListNode(5);

        two->next = one;
        one->next = fiv;

        std::vector<int> result   = nextLargerNodes(two);
        std::vector<int> expected = { 5,5,0 };
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        ListNode *two = new ListNode(2);
        ListNode *sev = new ListNode(7);
        ListNode *fou = new ListNode(4);
        ListNode *thr = new ListNode(3);
        ListNode *fiv = new ListNode(5);

        two->next = sev;
        sev->next = fou;
        fou->next = thr;
        thr->next = fiv;

        std::vector<int> result   = nextLargerNodes(two);
        std::vector<int> expected = { 7,0,5,5,0 };
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
