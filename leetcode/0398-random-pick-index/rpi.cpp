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


class Solution {
public:
    std::unordered_map<int,std::vector<int>> indexes;
    Solution(std::vector<int>& nums)
    {
        for(int index=0;index<nums.size();index++)
        {
            int value = nums[index];
            indexes[value].push_back(index);
        }
    }
    
    int pick(int target)
    {
        std::vector<int> &curr = indexes[target];
        if( curr.size() == 1 )
            return curr[0];
        int rindex = rand() % curr.size() ;
        return curr[rindex];
    }
};

int main(int argc, char **argv)
{
    std::cout << std::endl << "0398-random-pick-index" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {1,2,3,3,3};
        Solution *sol = new Solution(nums);
        sol->pick(1);
        int expected = 1;
        int result = 1;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
