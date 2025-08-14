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


struct IntervalComparer
{
    bool operator ()(const std::vector<int> &lhs, const std::vector<int> &rhs)
    {
        if( lhs[0] < rhs[0] )
            return true;
        if( lhs[0] == rhs[0] )
            return lhs[1] < rhs[1];
        return false;
    }
};

bool canAttendMeetings(std::vector<std::vector<int>> &intervals)
{
    std::priority_queue<std::vector<int>,
                        std::vector<std::vector<int>>,
                        IntervalComparer> meetings;

    for(auto current_meeting : intervals )
    {
        meetings.push( current_meeting );
    }


    if( meetings.size() <= 1 )
        return true;

    std::vector<int> prev;

    prev = meetings.top();
    meetings.pop();
    
    while( ! meetings.empty() )
    {
        std::vector<int> top = meetings.top();
        //        std::cout << "comparing " << prev[0] << "," << prev[1] << " - " << top[0] << "," << top[1] << std::endl;
        if( prev[0] < top[1] )
        {
            //            std::cout << "\tyes overlap" << std::endl;
            return false;
        }
        //        std::cout << "\tno overlap" << std::endl;
        prev = top;
        meetings.pop();
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0252-meeting-rooms" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> intervals = {{0,30}, {15,2},{5,10}};
        bool expected = false;
        bool result = canAttendMeetings(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> intervals = {{2,4},{7,10}};
        bool expected = true;
        bool result = canAttendMeetings(intervals);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
