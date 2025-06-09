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
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    return nullptr;
}

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


std::vector<int> testFunc( std::vector<int> &nums )
{
    std::vector<int> retval = nums;
    std::unordered_map<int,int> psums;
    int running_total;
    for(int index=0;index<nums.size();index++)
    {
    }
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1171-remove-zero-sum-consecutive-nodes-from-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums     = {1,2,-3,3,1};
        std::vector<int> expected = {3,1};
        std::vector<int> result   = testFunc( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
