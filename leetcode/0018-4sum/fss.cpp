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


std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
{
    std::sort(nums.begin(),nums.end());
    int N = nums.size();
    for(int first = 0;first< (N-3) ;first++)
    {
        for(int second = 1; second<(N-2_;second++)
        {
            int base = nums[first]+nums[second];
            int low = second+1;
            int high = N-1;
            
        }
    }
    std::vector<std::vector<int>> retval;
    return retval;        
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0018-4sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,0,-1,0,-2,2};
        int target = 0;
        fourSum(nums,target);
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
