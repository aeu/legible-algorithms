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


void dumpValues(std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ",";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

std::vector<int> countBits(int n)
{
    std::vector<int> ones;
    for(int index=0;index<=n;index++)
    {
        int bitmask = index;
        int bit = 0;
        while( bitmask )
        {
            if( bitmask & 1 )
                 bit++;
             bitmask >>= 1;
        }
        ones.push_back(bit);
    }
    return ones;
}
    
int main(int argc, char **argv)
{
    std::cout << "Leetcode #338 - Counting Bits" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        int n = 2;
        std::cout << "Input: n = " << n << std::endl;
        auto ones = countBits(n);
        dumpValues(ones);

    }
    {
        std::cout << "Example 2" << std::endl;
        int n = 5;
        std::cout << "Input: n = " << n << std::endl;
        auto ones = countBits(n);
        dumpValues(ones);
    }
    return -1;
}
