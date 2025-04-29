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
    bool first = true;
    for( const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << curr ;
    }
    std::cout << std::endl;
}
            
std::vector<int> findBuildings(std::vector<int>& heights)
{
    std::vector<int> retval;
    int tallest_so_far = 0;
    for(int index=heights.size()-1;index>=0;index--)
    {
        if( heights[index] > tallest_so_far )
        {
            tallest_so_far = heights[index];
            retval.push_back(index);
        }
    }
    std::reverse(retval.begin(),retval.end());
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1762-buildings-with-an-ocean-view" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> heights  = {4,2,3,1};
        std::vector<int> expected = {0,2,3};
        std::vector<int> result = findBuildings( heights );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> heights  = {4,3,2,1};
        std::vector<int> expected = {0,1,2,3};
        std::vector<int> result = findBuildings( heights );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> heights  = {1,3,2,4};
        std::vector<int> expected = {3};
        std::vector<int> result = findBuildings( heights );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
