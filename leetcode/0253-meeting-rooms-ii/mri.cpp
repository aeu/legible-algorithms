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

bool SortRooms(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    return lhs[0] < rhs[0];
}

int minMeetingRooms(std::vector<std::vector<int>>& intervals)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> in_use;
    std::sort( intervals.begin(), intervals.end(), SortRooms );
    for(const auto curr : intervals )
    {
        if( in_use.empty() )
        {
            in_use.push( curr[1] );
        }
        else
        {
            int in_use_end = in_use.top();
            if( curr[0] < in_use_end )
            {
                in_use.push(curr[1]);
            }
            else
            {
                in_use.pop();
                in_use.push(curr[1]);
            }
        }
    }
    return in_use.size();
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0253-meeting-rooms-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>>  intervals = {{0,30},{5,10},{15,20}};
        int expected = 2;
        int result = minMeetingRooms(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>>  intervals = {{7,10},{2,4}};
        int expected = 1;
        int result = minMeetingRooms(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
