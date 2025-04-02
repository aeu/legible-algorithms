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
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <limits.h>

void dumpValues(std::vector<int> values)
{
    for(auto curr : values )
    {
        std::cout << curr << ", ";
    }
    std::cout << std::endl;
}



void backtrack(std::vector<int> &candidates,
               int candidate_index,
               int target,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval,
               std::set<std::vector<int>> &seen)
{
    // std::cout << "bt called " << std::endl;
    // std::cout << "ci called " << candidate_index << std::endl;
    // std::cout << "t called "  << target << std::endl;
    if( target == 0 )
    {
        std::sort(path.begin(),path.end());
        if( seen.count( path ) == 0 )
        {
            retval.push_back(path);
            seen.insert(path);
        }
    }
    for(int index=candidate_index;index<candidates.size();index++)
    {
        // std::cout << "looop" << std::endl;
        if( candidates[index] > target )
            continue;
        path.push_back( candidates[index] );
        backtrack(candidates,index+1,target-candidates[index],path,retval,seen);
        path.pop_back();
    }
}
    

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                              int target)
{
    std::sort(candidates.begin(),candidates.end());
    int candidate_index = 0;
    std::vector<int> path;
    std::vector<std::vector<int>> retval;
    std::set<std::vector<int>> seen;
    std::cout << "cs" << candidates.size() << std::endl;
    backtrack( candidates, candidate_index, target, path, retval,seen);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 0040 - Combination Sum II" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> candidates = { 10,1,2,7,6,1,5 };
        int target = 8;
        std::vector<std::vector<int>> expected = {{1,1,6},{1,2,5},{1,7},{2,6}};
        std::vector<std::vector<int>> result = combinationSum2(candidates,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> candidates = { 2,5,2,1,2 };
        int target = 5;
        std::vector<std::vector<int>> expected = {{1,2,2},{5}};
        std::vector<std::vector<int>> result = combinationSum2(candidates,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
