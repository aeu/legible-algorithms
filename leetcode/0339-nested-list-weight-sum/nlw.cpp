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

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    
    // Constructor initializes a single integer.
    NestedInteger(int value);
    
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};


int dfs(const NestedInteger &ni, int depth)
{
    int retval = 0;
    if( ni.isInteger() )
    {
        retval = ni.getInteger() * depth ;
    }
    else
    {
        std::vector<NestedInteger> ni_list = ni.getList();
        for( auto const &curr : ni_list )
        {
            retval += dfs(curr,depth+1);
        }
    }
    return retval;
}


int depthSum(std::vector<NestedInteger>& nestedList)
{
    int retval = 0;
    for( auto const &curr : nestedList )
    {
        retval += dfs( curr, 1 );
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0339-nested-list-weight-sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
