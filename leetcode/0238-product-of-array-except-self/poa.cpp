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

void dumpValues(std::vector<int> vals)
{
    for( auto curr : vals )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    std::vector<int> retval     = std::vector<int>( nums.size(),0 );
    std::vector<int> left_pass  = std::vector<int>( nums.size(),0 );
    std::vector<int> right_pass = std::vector<int>( nums.size(),0 );

    left_pass[0] = 1;
    
    for(int index = 1; index < nums.size();index++)
    {
        left_pass[index] = nums[index-1] * left_pass[index-1];
    }

    right_pass[ nums.size()-1] = 1;

    for(int index=nums.size()-2;index>=0;index--)
    {
        right_pass[index] = nums[index+1] * right_pass[index+1];
    }

    for(int index = 0; index < nums.size();index++)
    {
        if( index == 0 )
            retval[index] = right_pass[index];
        else if ( index == nums.size() -1 )
            retval[index] = left_pass[index];
        else
            retval[index] = left_pass[index] * right_pass[index];
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "238 Product of Array Except Self" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,4};
        std::vector<int> expected = { 24,12,8,6 };
        std::vector<int> result = productExceptSelf( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {-1,1,0,-3,3};
        std::vector<int> expected = {0,0,9,0,0};
        std::vector<int> result = productExceptSelf( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
