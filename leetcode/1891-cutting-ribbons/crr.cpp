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

bool canCutKRibbonsOfLength(int k,
                            int length,
                            std::vector<int>& ribbons)
{
    int ribbon_count = 0;
    for(const auto curr : ribbons )
    {
        ribbon_count += curr / length;
    }
    if( ribbon_count >= k  )
        return true;
    return false;
}


int maxLength(std::vector<int>& ribbons, int k)
{
    int max_length = 0;
    int low = 1;
    int high = *std::max_element(ribbons.begin(),ribbons.end());
    while( low <= high )
    {
        int mid = low + (( high - low ) / 2 );
        bool cancut = canCutKRibbonsOfLength(k,mid,ribbons);
        if( cancut == false )
        {
            high = mid-1;
        }
        else
        {
            max_length = std::max(max_length, mid );
            low = mid+1;
        }
    }
    return max_length;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1891-cutting-ribbons" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> ribbons  = {9,7,5};
        int k = 3;
        int expected = 5;
        int result = maxLength(ribbons,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> ribbons  = {7,5,9};
        int k = 4;
        int expected = 4;
        int result = maxLength(ribbons,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> ribbons  = {5,7,9};
        int k = 22;
        int expected = 0;
        int result = maxLength(ribbons,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> ribbons  =
            {100000,100000,100000,100000,100000,100000,100000,100000,100000,
             100000,100000,100000,100000,100000,100000,100000,100000,100000,
             100000,100000,1,100000,100000,100000,100000,100000,100000,100000,
             100000,100000,100000,100000,100000,100000,100000,100000,100000,
             100000,100000,100000,100000,100000,100000,100000,100000,100000,
             100000,100000,100000,100000};

        int k = 49;
        int expected = 100000;
        int result = maxLength(ribbons,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;


}
