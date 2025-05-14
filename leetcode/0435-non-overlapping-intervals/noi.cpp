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


bool intervalsOverlap(const std::vector<int> &a, const std::vector<int> &b)
{
    if( ( a[1] <= b[0] ) || ( b[1] <= a[0] ))
        return false;
    return true;
}

void dumpIntervals(std::vector<std::vector<int>>& intervals)
{
    for(const auto &curr : intervals )
    {
        std::cout << curr[0] << "-" << curr[1] << std::endl;
    }
}

bool IntervalSort (const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    return lhs[1] < rhs[1];
}


int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
    int retval = 0;
    std::sort(intervals.begin(),intervals.end(),IntervalSort);
    int end = INT_MIN;
    int count = 0;
    for(const std::vector<int> &curr : intervals )
    {
        if( curr[0] >= end )
        {
            end = curr[1];
            count++;
        }
    }
    return intervals.size() - count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0435-non-overlapping-intervals" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
        int expected = 1;
        int result = eraseOverlapIntervals(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> intervals = {{1,2},{1,2},{1,2}};
        int expected = 2;
        int result = eraseOverlapIntervals(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> intervals = {{1,2},{2,3}};
        int expected = 0;
        int result = eraseOverlapIntervals(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
