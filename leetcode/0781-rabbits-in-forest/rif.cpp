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

int numRabbits(std::vector<int>& answers)
{
    std::unordered_map<int,int> distribution;
    for(const auto &curr :  answers )
    {
        distribution[curr]++;
    }
    int retval = 0;
    for( const auto [key, num_groups] : distribution )
    {
        int group_size = key + 1;   // the rabbit itself, plus others
        int colour_groups = ( num_groups + key ) / group_size;
        retval += colour_groups * group_size;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0781-rabbits-in-forest" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,0,1,0,0};
        int expected = 5;
        int result = numRabbits(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,1,2};
        int expected = 5;
        int result = numRabbits(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {10,10,10};
        int expected = 11;
        int result = numRabbits( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
