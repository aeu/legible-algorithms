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

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> retval;
    std::unordered_set<int> first_pass;
    std::unordered_set<int> intersection;
    
    for(const auto &curr : nums1 )
    {
        first_pass.insert(curr);
    }
    for(const auto &curr : nums2 )
    {
        if( first_pass.count(curr) )
            intersection.insert(curr);
    }
    for( const auto &curr : intersection )
    {
        retval.push_back( curr );
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0349-intersection-of-two-arrays" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums1    = {1,2,2,1};
        std::vector<int> nums2    = {2,2};
        std::vector<int> expected = {2};
        
        std::vector<int> result = intersection(nums1,nums2); 
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums1    = {4,9,5};
        std::vector<int> nums2    = {9,4,9,8,4};
        std::vector<int> expected = {9,4};
        
        std::vector<int> result = intersection(nums1,nums2); 
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
