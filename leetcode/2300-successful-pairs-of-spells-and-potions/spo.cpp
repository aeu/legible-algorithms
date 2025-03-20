// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

void dumpValues(std::vector<int> values )
{
    for( auto current: values )
        std::cout << current << ", " ;
    std::cout << std::endl;
}


int firstSuccessfulPotion(int spell,
                          std::vector<int> &potions,
                          long long success )
{
    //    std::cout << "fsp called with spell : " << spell << " and success : " << success << std::endl;
    int low = 0;
    int high = potions.size() -1 ;
    int mid = low + (high - low ) / 2 ;
    int did_succeed = false;
    while( low <= high )
    {
        //        std::cout << "\tL: " << low << " M: " << mid << " H: " << high << std::endl;
        int strength = potions[mid] * spell;
        //        std::cout << "\tStrength: " << strength << std::endl;
        if( strength >= success )
        {
            high = mid;
            did_succeed = true;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low ) / 2 ;        
        //        std::cout << "\tEOL L: " << low << " M: " << mid << " H: " << high << std::endl;
        if(( low == high ) && ( did_succeed == true ))
            break;
    }
    if( did_succeed == true )
    {
        //        std::cout << "fsp returning : " << mid << " which corresponds to " << potions[mid] << std::endl;
        return mid;
    }
    //    std::cout << "fsp returning : -1" << std::endl;
    return -1;
}


std::vector<int> successfulPairs(std::vector<int> &spells,
                                 std::vector<int> &potions,
                                 long long success)
{
    std::vector<int> retval;
    std::sort( potions.begin(), potions.end());
    for(auto current : spells )
    {
        int fsp = firstSuccessfulPotion( current, potions, success );
        if( fsp == -1 )
            retval.push_back( 0 );
        else
            retval.push_back(potions.size() - fsp);
    }
    return retval;
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        int success = 25;
        std::vector<int> spells   = { 1,2,3,4,5,6,7 };
        std::vector<int> potions  = { 1,2,3,4,5,6,7 };
        std::vector<int> expected = { 0,0,0,1,3,3,4 };
        std::vector<int> result   = successfulPairs(spells,potions,success);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int success = 7;
        std::vector<int> spells   = { 5,1,3};
        std::vector<int> potions  = { 1,2,3,4,5 };
        std::vector<int> expected = { 4,0,3 };
        std::vector<int> result   = successfulPairs(spells,potions,success);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int success = 16;
        std::vector<int> spells   = { 3,1,2};
        std::vector<int> potions  = { 8,5,8};
        std::vector<int> expected = { 2,0,2 };
        std::vector<int> result   = successfulPairs(spells,potions,success);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
