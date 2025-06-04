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


bool canShipWithinNDays(std::vector<int>& weights,
                        int days,
                        int capacity)
{
    int payload = 0;
    int num_days = 1;
    int index = 0;
    while(index < weights.size() )
    {
        int next = weights[index];
        if( ( payload + next ) <= capacity )
        {
            std::cout << "day : " << num_days << " next : " << next << std::endl;
            payload += next;
        }
        else
        {
            payload = next;
            num_days++;
            if( num_days > days )
            {
                return false;
            }
        }
        index++;
    }
    return true;
}


int shipWithinDays(std::vector<int>& weights, int days)
{
    int low = 0;
    int high = 2;
    int mid = 0;
    while( low < high )
    {
        mid = low + ((high - low)/2);
        std::cout << "low : " << low << " mid: " << mid << " high: " << high << std::endl;
        bool canship = canShipWithinNDays(weights,days,mid);
        if( canship == true )
        {
            high = mid;
        }
        else
        {
            low = mid+1;
            high = high * 2;
        }
    }
    std::cout << "END low : " << low << " mid: " << mid << " high: " << high << std::endl;
    return low;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1011-capacity-to-ship-packages-within-d-days" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> weights  = {1,2,3,4,5,6,7,8,9,10};
        int days = 5;
        int expected = 15;
        int result = shipWithinDays(weights,days);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> weights  = {3,2,2,4,1,4};
        int days = 3;
        int expected = 6;
        int result = shipWithinDays(weights,days);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> weights  = {1,2,3,1,1};
        int days = 4;
        int expected = 3;
        int result = shipWithinDays(weights,days);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
