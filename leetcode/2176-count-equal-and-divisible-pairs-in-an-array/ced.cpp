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


int countPairs(std::vector<int>& nums, int k)
{
    std::unordered_map<int,std::vector<int>> counts;
    for(int index=0;index<nums.size();index++)
    {
        counts[nums[index]].push_back(index);
    }
    int retval = 0;
    for( const auto &[key, values] : counts )
    {
        for(int outer = 0;outer<values.size()-1;outer++)
        {
            for(int inner=outer+1;inner<values.size();inner++)
            {
                int product = values[outer] * values[inner];
                if( ! ( product % k ))
                {
                    retval++;
                }
            }
        }
    }
    return retval;
}

int main(int argc, char **argv)
    
{
    std::cout << std::endl << "2176-count-equal-and-divisible-pairs-in-an-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {3,1,2,2,2,1,3};
        int expected = 4;
        int k = 2;
        int result = countPairs(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,3,4};
        int expected = 0;
        int k = 1;
        int result = countPairs(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
