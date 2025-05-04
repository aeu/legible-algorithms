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

static bool tsort(const std::pair<char,int> &lhs,
                  const std::pair<char,int> &rhs)
{
    return lhs.second > rhs.second;
}

int leastInterval(std::vector<char>& tasks, int n)
{
    int interval = 0;
    std::unordered_map<char,int> freq;
    for(auto current : tasks )
    {
        freq[current]++;
    }
    int most_frequent = 0;
    int num_at_max = 0;
    for( const auto &[task, frequency] : freq )
    {
        if( frequency > most_frequent )
        {
            most_frequent = frequency;
            num_at_max = 1;
        }
        else if( frequency == most_frequent )
        {
            num_at_max++;
        }
    }
    int calc = ( most_frequent - 1 ) * ( n + 1 ) + num_at_max;
    interval = std::max( calc, (int)tasks.size());
    return interval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC621 Task Scheduler" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        int n = 2;
        int expected = 8;
        int result = leastInterval(tasks,n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<char> tasks = {'A','C','A','B','D','B'};
        int n = 1;
        int expected = 6;
        int result = leastInterval(tasks,n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        int n = 0;
        int expected = 10;
        int result = leastInterval(tasks,n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        int n = 3;
        int expected = 10;
        int result = leastInterval(tasks,n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
