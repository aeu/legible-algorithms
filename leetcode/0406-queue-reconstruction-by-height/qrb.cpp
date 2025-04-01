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

void dumpHeights(std::vector<std::vector<int>> heights)
{
    for(auto curr : heights )
    {
        std::cout << "{" << curr[0] << "," << curr[1] << "}, " ;
    }
    std::cout << std::endl;
}
   

static bool compareHeights(const std::vector<int> lhs, const std::vector<int> rhs)
{
    if( lhs[0] != rhs[0] )
        return lhs[0] > rhs[0];
    return lhs[1] < rhs[1];
}


std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
{
    std::sort(people.begin(), people.end(), compareHeights );

    std::vector<std::vector<int>> retval;
    for(auto curr : people )
    {
        retval.insert( retval.begin() + curr[1], curr );
    }
    
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> people   = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        std::vector<std::vector<int>> expected = {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
        std::vector<std::vector<int>> result    = reconstructQueue(people);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> people   = {{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
        std::vector<std::vector<int>> expected = {{3,0},{6,0},{7,0},{5,2},{3,4},{5,3},{6,2},{2,7},{9,0},{1,9}};
        std::vector<std::vector<int>> result    = reconstructQueue(people);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}





