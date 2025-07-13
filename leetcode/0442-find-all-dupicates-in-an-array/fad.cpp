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

// the clue here is that you have to use constant space, which means
// you have to use the input data itself to store data in as you go.
// the "at most twice" means that there's two stages for every
// inteteger.  seen once, and then seen a second time.  this means you
// can use the sign to store progress.

std::vector<int> findDuplicates(std::vector<int>& nums)
{
    std::vector<int> retval;
    for(auto curr : nums )
    {
        int val = abs(curr);
        int index = val - 1;
        if( nums[index] < 0 )
        {
            retval.push_back( val );
        }
        else
        {
            nums[index] *= -1;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0442-find-all-dupicates-in-an-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {4,3,2,7,8,2,3,1};
        std::vector<int> expected = {2,3};
        std::vector<int> result = findDuplicates(nums);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,2};
        std::vector<int> expected = {1};
        std::vector<int> result = findDuplicates(nums);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1};
        std::vector<int> expected = {};
        std::vector<int> result = findDuplicates(nums);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
