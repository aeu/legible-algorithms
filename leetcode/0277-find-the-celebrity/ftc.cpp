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

bool knows(int a, int b)
{
    return true;
}

int findCelebrity(int n)
{
    // first pass, make sure that our candidate doesn't know anyone
    int candidate = 0;
    for(auto index = 1; index < n ; index++)
    {
        if( knows(candidate,index) )
            candidate = index;
    }
    // at this point we have a candidate that doesn't know anyone after him,
    // but he may have known people before him.

    for(auto index = 0; index < n; index++)
    {
        if( candidate == index )
            continue;
        if( knows( candidate, index ) )
            return -1;
        if( ! knows( index, candidate ) )
            return -1;
    }
    return candidate;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0277-find-the-celebrity" << std::endl << std::endl;
    std::cout << std::endl << "This one requires a function on leetcode, so no test harness" << std::endl << std::endl;
    return 0;
}
