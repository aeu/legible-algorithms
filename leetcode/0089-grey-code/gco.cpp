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


std::vector<int> grayCode(int n)
{
    std::vector<int> retval;
    int limit = 2 << (n-1);
    std::cout << "limit is " << limit << std::endl;
    for(int index =0; index < limit; index++)
    {
        int gval = index ^ ( index >> 1 );
        std::cout << "gval (" << index << ") " << gval << std::endl;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "/leetcode/0089-grey-code/" << std::endl << std::endl;
    int test_case = 1;
    {
        grayCode(2);
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
