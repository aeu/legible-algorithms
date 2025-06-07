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


bool canMakeBouquets(std::vector<int>& bloomDay,
                     int m,
                     int k,
                     int day)
{
    int flower_count = 0;
    int bouquet_count = 0;
    for(int index=0;index<bloomDay.size();index++)
    {
        int curr = bloomDay[index]; 
        if( curr <= day )
        {
            flower_count++;
        }
        else
        {
            if( flower_count > 0 )
            {
                bouquet_count += flower_count / k;
                flower_count = 0;
            }
        }
    }
    if( flower_count > 0 )
    {
        bouquet_count += flower_count / k;
    }
    
    return bouquet_count >= m;
}


int minDays(std::vector<int>& bloomDay, int m, int k)
{
    auto minmax = std::minmax_element(bloomDay.begin(), bloomDay.end());
    int low = *minmax.first;
    int high = *minmax.second;
    int min_days = INT_MAX;
    while( low <= high )
    {
        int mid = low + (( high - low ) / 2 );
        bool canmake = canMakeBouquets(bloomDay,m,k,mid);
        if( canmake == true )
        {
            min_days = std::min(min_days,mid);
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if( min_days == INT_MAX )
        return -1;
    return min_days;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1482-minumum-number-of-days-to-make-m-bouquets" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> bloomDay  = {1,10,3,10,2};
        int m = 3;
        int k = 1;
        int expected = 3;
        int result = minDays(bloomDay, m, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> bloomDay  = {1,10,3,10,2};
        int m = 3;
        int k = 2;
        int expected = -1;
        int result = minDays(bloomDay, m, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> bloomDay  = {7,7,7,7,12,7,7};
        int m = 2;
        int k = 3;
        int expected = 12;
        int result = minDays(bloomDay, m, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
