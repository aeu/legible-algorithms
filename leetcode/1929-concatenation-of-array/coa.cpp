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


std::vector<int> getConcatenation(std::vector<int>& nums)
{
    std::vector<int> retval = nums;
    for(const auto &curr : nums )
    {
        retval.push_back(curr);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1929-concatenation-of-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,1};
        std::vector<int> expected  = {1,2,1,1,2,1};
        std::vector<int> result = getConcatenation(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,3,2,1};
        std::vector<int> expected  = {1,3,2,1,1,3,2,1};
        std::vector<int> result = getConcatenation(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
