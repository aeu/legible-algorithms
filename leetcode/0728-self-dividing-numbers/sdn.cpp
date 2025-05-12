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

std::vector<int> selfDividingNumbers(int left, int right)
{
    std::vector<int> retval;
    for(int index=left;index<=right;index++)
    {
        bool should_add = true;
        int current = index;
        while( current > 0 )
        {
            int digit = current % 10;
            if( digit == 0 )
            {
                should_add = false;
                break;
            }
            if( index % digit )
            {
                should_add = false;
                break;
            }
            current /= 10;
        }
        if( should_add )
            retval.push_back(index);
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0728-self-dividing-numbers" << std::endl << std::endl;
    int test_case = 1;
    {
        int left = 1;
        int right = 22;
        std::vector<int> result = selfDividingNumbers(left,right);
        std::vector<int> expected = {1,2,3,4,5,6,7,8,9,11,12,15,22};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int left = 47;
        int right = 85;
        std::vector<int> result = selfDividingNumbers(left,right);
        std::vector<int> expected = {48,55,66,77};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
