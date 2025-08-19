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


int numSubarrayProductLessThanK(std::vector<int>& nums, int k) 
{
    int subarray_count = 0;

    for(int index=0;index<nums.size();index++)
    {
        int inner = index;
        int product = 1;
        while( inner < nums.size())
        {
            product *= nums[inner];
            if( product < k )
                subarray_count++;
            else
                break;
            inner++;
        }
    }
    return subarray_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0713-subarray-product-less-than-k" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {10,5,2,6};
        int k = 100;
        int expected = 8;
        int result = numSubarrayProductLessThanK(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
