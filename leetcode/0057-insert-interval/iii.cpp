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

bool overlaps(std::vector<int> first, std::vector<int> second)
{
    if( (second[0] >= first[0]) && ((second[0]) <= first[1]))
    {
        return true;
    }
    if( (first[0] >= second[0]) && ((first[0]) <= second[1]))
    {
        return true;
    }
    return false;
}

std::vector<int> merge(std::vector<int> first, 
                       std::vector<int> second)
{
    std::vector<int> retval;
    retval.push_back( std::min( first[0], second[0]));
    retval.push_back( std::max( first[1],second[1]));
    return retval;
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, 
                                     std::vector<int>& newInterval) 
{
    std::vector<std::vector<int>> retval;
    for(auto curr : intervals )
    {
        if( retval.empty())
            retval.push_back( curr );
        
        std::vector<int> &last = retval.back();
        if( overlaps( ))
    }        
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0057-insert-interval" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
