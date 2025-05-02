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

int findNumbers(std::vector<int>& nums)
{
    int even_count = 0;
    for(auto curr : nums )
    {
        int digits = 0;
        while( curr > 0 )
        {
            curr /=10;
            digits++;
        }
        if( ! ( digits % 2 ))
        {
            even_count++;
        }
    }
    return even_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1295-find-numbers-with-even-number-of-digits" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {12,345,2,6,7896};
        int expected = 2;
        int result = findNumbers(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {555,901,482,1771};
        int expected = 1;
        int result = findNumbers(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
