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

void rotate(std::vector<int>& nums, int k)
{
    int rem = k % nums.size();
    std::reverse( nums.begin(), nums.end() );
    std::reverse( nums.begin(), nums.begin()+rem);
    std::reverse( nums.begin()+rem, nums.end());
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "189 Rotate Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {1,2,3,4,5,6,7};
        int k = 3;
        std::vector<int> expected ={5,6,7,1,2,3,4};
        rotate(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == nums ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums =  {-1,-100,3,99};
        int k = 2;
        std::vector<int> expected = {3,99,-1,-100};
        rotate(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == nums ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
