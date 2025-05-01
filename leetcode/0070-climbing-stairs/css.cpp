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
#include <set>
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


int backtrack(int n,
              int start_point,
              std::vector<int> &current_path,
              std::set<std::vector<int>> &paths)
{
    std::cout << "in backtrack, n: " << n << " start_point: " << start_point << std::endl;
    // exit condition
    if( start_point == n )
    {
        if( paths.count( current_path ) )
        {
            dumpValues( current_path );
            paths.insert( current_path );
        }
    }

    for(int index=start_point;index<n;index++)
    {
        // first try going up 1 stair
        std::cout << "I still can go : " << ( n - index ) << " stairs " << std::endl;
        if((n - index) >= 1)
        {
            current_path.push_back(1);
            backtrack(n,start_point+index+1,current_path,paths);
            current_path.pop_back();
        }
        // now try goign up 2 stairs
        if((n - index) >= 2)
        {
            current_path.push_back(2);
            backtrack(n,start_point+index+2,current_path,paths);
            current_path.pop_back();
        }
    }
    return 0;
}


int climbStairs(int n)
{
    std::vector<int> current_path;
    std::set<std::vector<int>> paths;
    int retval = backtrack(n,0,current_path,paths);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0070-climbing-stairs" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 2;
        int expected = 2;
        int result = climbStairs(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 3;
        int expected = 3;
        int result = climbStairs(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
