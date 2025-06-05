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

void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


bool canBeMade(int candidate, std::unordered_map<int,int> &counts)
{
    auto lcounts = counts;
    int lcandidate = candidate;

    while( lcandidate > 0 )
    {
        int digit = lcandidate % 10 ;
        lcounts[digit]--;
        if( lcounts[digit] < 0 )
            return false;
        lcandidate /= 10;
    }
    return true;
}


std::vector<int> findEvenNumbers(std::vector<int>& digits)
{
    std::vector<int> retval;
    if( digits.size() < 3 )
        return retval;
    bool has_even = false;
    std::unordered_map<int,int> counts;
    for(auto curr : digits )
    {
        if( ! ( curr % 2 ) )
        {
            has_even = true;
        }
        counts[curr]++;
    }
    if( ! has_even )
    {
        return retval;
    }
    for(int index=100;index<999;index+=2)
    {
        if( canBeMade(index,counts) )
            retval.push_back(index);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2094-finding-3-digit-even-numbers" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums     = {2,1,3,0};
        std::vector<int> expected = {102,120,130,132,210,230,302,310,312,320};
        std::vector<int> result   = findEvenNumbers(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums     = {2,2,8,8,2};
        std::vector<int> expected = {222,228,282,288,822,828,882};
        std::vector<int> result   = findEvenNumbers(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums     = {3,7,5};
        std::vector<int> expected = {};
        std::vector<int> result   = findEvenNumbers(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
