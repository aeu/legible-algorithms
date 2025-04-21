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

std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                    std::vector<int>& nums2)
{
    std::vector<int> retval;
    std::unordered_map<int,int> next_greater;
    std::stack<int> mstack;
    for(int index=0;index<nums2.size();index++)
    {
        next_greater[nums2[index]] = -1;
        while(( ! mstack.empty() ) && ( nums2[index] > mstack.top() ))
        {
            int popped = mstack.top();
            next_greater[popped] = nums2[index];
            mstack.pop();
        }
        mstack.push( nums2[index] );
    }

    for(const auto &curr: nums1 )
    {
        retval.push_back( next_greater[curr] );
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0496-next-greater-element-i" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums1  = {4,1,2};
        std::vector<int> nums2  = {1,3,4,2};
        std::vector<int> expected = {-1,3,-1};
        std::vector<int> result = nextGreaterElement(nums1, nums2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums1  = {2,4};
        std::vector<int> nums2  = {1,2,3,4};
        std::vector<int> expected = {3,-1};
        std::vector<int> result = nextGreaterElement(nums1, nums2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
