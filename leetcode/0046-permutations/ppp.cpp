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


void generatePermutations(std::vector<int> &nums,
                          int size,
                          std::vector<std::vector<int>> retval)
{
    if(size == 1 )
    {
        retval.push_back(nums);
    }
    else
    {
        for(int index=0;index<size;index++)
        {
            generatePermutations(nums,size-1,retval);
            if( index & 1 )
            {
                std::swap(nums[0],nums[size-1]);
            }
            else
            {
                std::swap(nums[index],nums[size-1]);
            }
        }
    }
}
    


std::vector<std::vector<int>> permute(std::vector<int> nums)
{
    std::vector<std::vector<int>> retval;
    generatePermutations(nums,nums.size(),retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC46 - Permutations" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        std::vector<std::vector<int>> expected = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
        std::vector<std::vector<int>> result   = permute(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {0,1};
        std::vector<std::vector<int>> expected = {{0,1},{1,0}};
        std::vector<std::vector<int>> result   = permute(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {1};
        std::vector<std::vector<int>> expected = {{1}};
        std::vector<std::vector<int>> result   = permute(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
