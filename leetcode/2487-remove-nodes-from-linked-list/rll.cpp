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

ListNode *removeNodes(ListNode *head)
{
    
}

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
        while(( ! gstack.empty() ) && ( nums[gstack.top()] > nums[index]))
        {
            greaters[index] = gstack.top();
            gstack.pop();
        }
        gstack.push(index);
    }
    dumpVector(greaters);
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2487-remove-nodes-from-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {5,2,13,3,8};
        testRemoveNodes(nums);
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
