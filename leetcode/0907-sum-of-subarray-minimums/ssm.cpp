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

int sumSubarrayMins(std::vector<int>& arr)
{
    std::stack<int> mstack;
    std::vector<int> lefts(arr.size(),-1);
    std::vector<int> rights(arr.size(),0);
    for(int index=0;index<arr.size();index++)
    {
        while( ( ! mstack.empty() ) && ( arr[ mstack.top()] > arr[index] ))
        {
            mstack.pop();
        }

        if( ! mstack.empty() )
            lefts[index] = index - mstack.top();
        else
            lefts[index] = index + 1;
            
        mstack.push(index);
    }
    while( !mstack.empty() )
        mstack.pop();
    
    for(int index=arr.size()-1;index>=0;index--)
    {
        while( ( ! mstack.empty() ) && ( arr[ mstack.top() ] >= arr[index] ))
        {
            rights[index] = mstack.top();
            mstack.pop();
        }

        if( ! mstack.empty() )
            rights[index] = mstack.top() - index;
        else
            rights[index] = arr.size() - index;
        
        mstack.push(index);
    }
    long long left_count;
    long long right_count;
    long long total=0;
    for(int index=0;index<arr.size();index++)
    {
        total += static_cast<long long>(arr[index]) * lefts[index] * rights[index];
    }
    return static_cast<int>(total % 1000000007 );
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0907-sum-of-subarray-minimums" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> arr  = {3,1,2,4};
        int expected = 17;
        int result = sumSubarrayMins(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr  = {11,81,94,43,3};
        int expected = 444;
        int result = sumSubarrayMins(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
