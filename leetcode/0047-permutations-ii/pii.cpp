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


void backtrack(std::vector<int>& nums,
               std::vector<int> &used,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval)
{
    if( path.size() == nums.size() )
    {
        retval.push_back(path);
    }

    for(int index = 0;index<nums.size();index++)
    {
        if( used[index] )
            continue;
        
        if(( index > 0 ) && ( nums[index] == nums[index-1] ) && ( ! used[index-1] ))
            continue;

        used[index] = 1;
        path.push_back(nums[index]);
        backtrack( nums, used, path, retval );
        path.pop_back();
        used[index] = 0;
    }
}
               


std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
    std::vector<std::vector<int>> retval;
    std::vector<int> path;
    std::vector<int> used (nums.size(),0);
    std::sort(nums.begin(),nums.end());
    backtrack(nums, used, path, retval);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "47. Permutations II" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,2};
        std::vector<std::vector<int>> expected = {{1,1,2},{1,2,1},{2,1,1}};
        std::vector<std::vector<int>> result = permuteUnique(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {1,2,3};
        std::vector<std::vector<int>> expected = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
        std::vector<std::vector<int>> result = permuteUnique(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
