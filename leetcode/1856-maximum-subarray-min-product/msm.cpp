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
#include <span>


void dumpValues(std::vector<int> &values)
{
    std::cout << "[" ;
    bool first = true;
    for(const auto curr : values )
    {
        if( first )
            first = false;
        else
            std::cout << ", " ;
        std::cout << curr ;
    }
    std::cout << "]" << std::endl;
}

void dumpSpan(std::span<int> &values)
{
    std::cout << "[" ;
    bool first = true;
    for(const auto curr : values )
    {
        if( first )
            first = false;
        else
            std::cout << ", " ;
        std::cout << curr ;
    }
    std::cout << "]" << std::endl;
}

int maxSumMinProduct(std::vector<int> &nums )
{
    std::vector<int> lessers_left(nums.size(),-1);
    std::vector<int> lessers_right(nums.size(),nums.size());

    std::stack<int> monostack;
    for(int index=0;index<nums.size();index++)
    {
        while(( ! monostack.empty() ) && ( nums[ monostack.top()] >= nums[index] ))
            monostack.pop();

        lessers_left[index] = monostack.empty() ? -1 : monostack.top();
        monostack.push(index);
    }

    while( ! monostack.empty() )
        monostack.pop();

    for(int index=nums.size()-1;index>=0;index--)
    {
        while(( ! monostack.empty()) && ( nums[monostack.top()] >= nums[index]  ))
            monostack.pop();
        lessers_right[index] = monostack.empty() ? nums.size() : monostack.top();
        monostack.push(index);
    }

    std::vector<long long> prefix_sums(nums.size()+1,0);
    for(int index=0;index<nums.size();index++)
        prefix_sums[index+1] = nums[index] + prefix_sums[index];

    int start;
    int end;
    long long max = INT_MIN;
    for(int index=0;index<nums.size();index++)
    {
        if( lessers_left[index] == -1 )
            start = 0;
        else
            start = lessers_left[index] + 1;

        end = lessers_right[index];
        long long sum = prefix_sums[end] - prefix_sums[start];
        long long curmax = nums[index] * sum;
        max = std::max(max,curmax);
    }
    return max % 1000000007;

}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1856-maximum-subarray-min-product" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,2};
        int expected = 14;
        int result = maxSumMinProduct(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {2,3,3,1,2};
        int expected = 18;
        int result = maxSumMinProduct(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {3,1,5,6,4,2};
        int expected = 60;
        int result = maxSumMinProduct(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
