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


struct IntervalSort {
    bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs)
    {
        return lhs[0] < rhs[0];
    }
};

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    std::vector<std::vector<int>> retval;
    if( intervals.size() == 0 )
        return retval;
    
    std::sort( intervals.begin(), intervals.end(), IntervalSort() );
    retval.push_back( intervals[0]);
    for(int index=1;index<intervals.size();index++)
    {
        if( retval.back()[1] >= intervals[index][1] )
            
        std::cout << curr[0] << " - " << curr[1] << std::endl;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0056-merge-intervals" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
        std::vector<std::vector<int>> expected  = {{1,6},{8,10},{15,18}};
        std::vector<std::vector<int>> result    = merge(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> intervals = {{1,4},{4,5}};
        std::vector<std::vector<int>> expected  = {{1,5}};
        std::vector<std::vector<int>> result    = merge(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}




    
