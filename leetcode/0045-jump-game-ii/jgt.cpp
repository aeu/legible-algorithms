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

int jump(std::vector<int>& nums) 
{
    int jumps_made = 0;
    int curr_end = 0;
    int farthest = 0;
    int N = nums.size();

    // loop through every value in nums.  At each one, find out how far
    // we will get if we jump from that point, and keep track of that 
    // furthest point that we could have possibly gotten to.
    //
    // sooner or later, the current num will be equal to the farthest 
    // point.  when it is, update our ending point to the furthest, and
    // also increment the jumps made.

    for (int index = 0; index < N - 1; index++)
    {
        farthest = std::max(farthest, index + nums[index]);
        if (index == curr_end)
        {
            jumps_made++;
            curr_end = farthest;
        }
    }
    return jumps_made;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0045-jump-game-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {2,3,1,1,4};
        int expected = 2;
        int result = jump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {2,3,0,1,4};
        int expected = 2;
        int result = jump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
