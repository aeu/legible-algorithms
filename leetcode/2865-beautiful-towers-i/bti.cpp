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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


long long maximumSumOfHeights(std::vector<int>& heights)
{
    long long max_total = 0;
    for(int index=0;index<heights.size();index++)
    {
        int max_index = index;
        std::vector<int> inner_heights = heights;
        long long total = 0;
        int left = max_index - 1;
        int right = max_index + 1;
        while( left >= 0 )
        {
            if( inner_heights[left] > inner_heights[left+1] )
                inner_heights[left] = inner_heights[left+1];
            left--;
        }
        while( right < inner_heights.size())
        {
            if( inner_heights[right] > inner_heights[right-1] )
                inner_heights[right] = inner_heights[right-1];
            right++;
        }
        for( const auto curr : inner_heights )
            total += curr;
        max_total = std::max(total, max_total);
    }
    return max_total;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2865-beautiful-towers-i" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> heights  = {5,3,4,1,1};
        int expected = 13;
        int result = maximumSumOfHeights(heights);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> heights  = {6,5,3,9,2,7};
        int expected = 22;
        int result = maximumSumOfHeights(heights);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> heights  = {2,4,5,2,5,5,2,1,1,3};
        int expected = 23;
        int result = maximumSumOfHeights(heights);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> heights  = {5,5,3,2,6};
        int expected = 17;
        int result = maximumSumOfHeights(heights);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}


