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

std::vector<int> getIntersection(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    std::vector<int> intersection;
    int lhs_start = lhs[0];
    int lhs_end   = lhs[1];
    int rhs_start = rhs[0];
    int rhs_end   = rhs[1];

    int start = std::max( lhs_start, rhs_start );
    int end   = std::min( lhs_end,   rhs_end );

    if( start <= end )
    {
        intersection.push_back(start);
        intersection.push_back(end);
    }
    return intersection;
}

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList,
                                                   std::vector<std::vector<int>>& secondList)
{
    std::vector<std::vector<int>> retval;
    int findex = 0;
    int sindex = 0;
    while( ( findex < firstList.size() ) && ( sindex < secondList.size()))
    {
        auto inter = getIntersection( firstList[findex], secondList[sindex] );
        if( inter.size() > 0 )
            retval.push_back(inter);
        if( firstList[findex][1] < secondList[sindex][1] )
            findex++;
        else
            sindex++;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0986-interval-list-intersections" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
        std::vector<std::vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
        std::vector<std::vector<int>> expected = {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}};
        std::vector<std::vector<int>> result = intervalIntersection(firstList,secondList);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> firstList = {{1,3},{5,9}};
        std::vector<std::vector<int>> secondList = {};
        std::vector<std::vector<int>> expected = {};
        std::vector<std::vector<int>> result = intervalIntersection(firstList,secondList);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
