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

void dumpValues(std::vector<int> values)
{
    for(auto curr : values )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}

// this is a standard backtracking problem.  in this case we don't
// have an array of input elements, we just have a end point N which
// represents the highest number we can use.  At each step of the way
// add the next possible number.  our exit condition is when the path
// is of the right length
//
// setup
//    path being built
//    retval where the solutions are going
//
// backtrack
//    exit condition, are we the light length, if so, add to path
//    loop through remaining possible numbers
//    push next possible
//    backtrack
//    pop what we just added

void backtrack(int n,
               int k,
               int start,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval)
{
    if( path.size() == k )
    {
        retval.push_back(path);
        return;
    }
    for(int index=start;index<=n;index++)
    {
        path.push_back(index);
        backtrack(n,k,index+1,path,retval);
        path.pop_back();
    }
}
    
std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> path;
    std::vector<std::vector<int>> retval;
    backtrack(n,k,1,path,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 77 - Combinations" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 4;
        int k = 2;
        std::vector<std::vector<int>> expected = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
        std::vector<std::vector<int>> result = combine(n, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int n = 1;
        int k = 1;
        std::vector<std::vector<int>> expected = {{1}};
        std::vector<std::vector<int>> result = combine(n, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
