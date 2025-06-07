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


std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
{
    auto compare_lambda = [x](const int &a, const int &b)
        {
            if (abs(a - x) == abs(b - x))
                return a < b;
            return abs(a - x) < abs(b - x);
        };
    std::priority_queue<int,std::vector<int>, decltype(compare_lambda)> closest(compare_lambda);
    for( const auto &curr : arr )
    {
        closest.push(curr);
        if( closest.size() > k )
            closest.pop();
    }
    std::vector<int> retval;
    while( ! closest.empty() )
    {
        int top = closest.top();
        retval.push_back(top);
        closest.pop();
    }
    std::sort(retval.begin(), retval.end());
    return retval;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0658-find-k-closest-elements" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,4,5};
        int k = 4;
        int x = 3;
        std::vector<int> result = findClosestElements(nums,k,x);
        std::vector<int> expected = { 1,2,3,4};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,2,3,4,5};
        int k = 4;
        int x = -1;
        std::vector<int> result = findClosestElements(nums,k,x);
        std::vector<int> expected = { 1,1,2,3};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
