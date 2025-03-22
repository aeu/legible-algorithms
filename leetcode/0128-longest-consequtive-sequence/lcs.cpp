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
#include <unordered_map>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums)  \
{
    if( nums.size() == 1 )
        return 1;
    
    std::unordered_set<int> seen;
    for(auto current : nums )
    {
        seen.insert( current );
    }
    int longest_sequence = 0;
    for( auto current : seen )
    {
        int current_sequence = 0;
        auto it = seen.find(current-1 );
        if( it == seen.end())
        {
            current_sequence++;
            current++;
            it = seen.find( current );
            while( it != seen.end() )
            {
                current++;
                it = seen.find( current );
                current_sequence++;
            }
            longest_sequence = std::max(current_sequence, longest_sequence);
        }
    }
    return longest_sequence;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #128 - Longest Consecutive Sequence" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 0,0};
        int expected = 1;
        int result = longestConsecutive(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 100,4,200,1,3,2};
        int expected = 4;
        int result = longestConsecutive(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 0,3,7,2,5,8,4,6,0,1};
        int expected = 9;
        int result = longestConsecutive(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,0,1,2};
        int expected = 3;
        int result = longestConsecutive(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
