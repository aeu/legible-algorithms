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
#include <cstdint>

uint32_t reverseBits(uint32_t n )
{
    uint32_t retval = 0;
    uint32_t nmask  = 1;
    uint32_t rmask  = 1 << 31;
    for(int index=0;index<32;index++)
    {
        if( n & nmask )
            retval |= rmask;
        rmask = rmask >> 1 ;
        nmask = nmask << 1;
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        uint32_t n = 43261596;
        uint32_t expected = 964176192;
        uint32_t result = reverseBits( n );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        uint32_t n = 4294967293;
        uint32_t expected = 3221225471;
        uint32_t result = reverseBits( n );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
