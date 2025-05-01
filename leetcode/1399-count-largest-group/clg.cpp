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


int countLargestGroup(int n)
{
    std::vector<int> counts (10,0);
    for(int index=0;index<=n;index++)
    {
        int val = index;
        int digit_sum = 0;
        while( val > 0 )
        {
            digit_sum += val % 10;
            val /= 10;
        }
        counts[digit_sum]++;
    }
    int max = INT_MIN;
    for(int index=1;index<counts.size();index++)
    {
        int curr = counts[index];
        max = std::max( max, curr );
    }
    int count = 0;
    for(int index=1;index<counts.size();index++)
    {
        int curr = counts[index];
        if(curr == max )
            count++;
    }
    return count;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1399-count-largest-group" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 13;
        int expected = 4;
        int result = countLargestGroup(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 2;
        int expected = 2;
        int result = countLargestGroup(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
