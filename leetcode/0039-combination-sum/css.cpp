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


// this follows the standard backtracking pattern which is
// setup function
//
// backtrack
//    exit condition
//
//    push next candidate (if it won't go over target)
//    backtrack updated target and starting positon
//    pop
//

void backtrack(std::vector<int>& candidates,
               int target,
               int starting_candidate,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval )
{
    if( target == 0 )
        retval.push_back(path);

    for(int index = starting_candidate; index < candidates.size(); index++)
    {
        if( candidates[index] > target )
            continue;
        path.push_back(candidates[index]);
        backtrack( candidates, target - candidates[index], index, path, retval );
        path.pop_back();
    }
}
    
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int>> retval;
    std::vector<int> path;
    backtrack( candidates, target, 0, path, retval );
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC39 - Combination Sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> candidates  = {2,3,6,7};
        int target = 7;
        std::vector<std::vector<int>> expected = {{2,2,3},{7}};
        std::vector<std::vector<int>> result = combinationSum(candidates,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> candidates  = {2,3,5};
        int target = 8;
        std::vector<std::vector<int>> expected = {{2,2,2,2},{2,3,3},{3,5}};
        std::vector<std::vector<int>> result = combinationSum(candidates,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> candidates  = {2};
        int target = 1;
        std::vector<std::vector<int>> expected = {};
        std::vector<std::vector<int>> result = combinationSum(candidates,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
