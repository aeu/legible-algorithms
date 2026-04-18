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

int transform(int num, int a, int b, int c)
{
    int transform = ( a * num * num ) + ( b * num ) + c;
    return transform;
}

std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c)
{
    std::vector<int> results;
    std::unordered_map<int,int> memo;
    for(const auto current_number : nums )
    {
        if( memo.find(current_number) != memo.end() )
        {
            results.push_back( memo[current_number] );
        }
        else
        {
            int result = transform(current_number,a,b,c);
            memo[current_number ] = result;
            results.push_back( result );
        }
    }
    std::sort(results.begin(),results.end());
    return results;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0360-sort-transformed-array" << std::endl << std::endl;
    int test_case = 1;
    {
        int a = 1;
        int b = 3;
        int c = 5;
        std::vector<int> nums     = {-4,-2, 2,4};
        std::vector<int> expected = { 3, 9,15,33};
        std::vector<int> result   = sortTransformedArray(nums,a,b,c);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int a = -1;
        int b = 3;
        int c = 5;
        std::vector<int> nums     = {-4,-2, 2,4};
        std::vector<int> expected = {-23,-5,1,7};
        std::vector<int> result   = sortTransformedArray(nums,a,b,c);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
