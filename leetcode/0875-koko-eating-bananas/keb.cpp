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
#include <stack>

void dumpValues(std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int hoursNeededToEat(std::vector<int>& piles,
                     int hourly_rate)
{
    int hours_needed = 0;
    for(int pile : piles )
    {
        hours_needed += (pile + hourly_rate - 1) / hourly_rate; 
    }
    return hours_needed;
}


int minEatingSpeed(std::vector<int>& piles, int available_hours)
{
    auto min_max = std::minmax_element(piles.begin(), piles.end());
    int low  = *min_max.first;
    int high = *min_max.second;
    int mid;
    while( high > low )
    {
        mid = low + ( high - low ) / 2;
        int mid_hours = hoursNeededToEat(piles,mid);
        if ( mid_hours <= available_hours )
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #875 - Koko Eating Bananas" << std::endl << std::endl;
    {
        std::cout << std::endl << "Example 1" << std::endl;
        int available_hours = 8;
        std::vector<int> piles = {3,6,7,11};
        std::cout << "Piles: " ;
        dumpValues(piles);
        std::cout << "Hours available : " << available_hours << std::endl;
        int min_eating_speed = minEatingSpeed(piles,available_hours);
        std::cout << "Min eating speed " << min_eating_speed << std::endl;
        
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        int available_hours = 5;
        std::vector<int> piles = {30,11,23,4,20};
        std::cout << "Piles: " ;
        dumpValues(piles);
        std::cout << "Hours available : " << available_hours << std::endl;
        int min_eating_speed = minEatingSpeed(piles,available_hours);
        std::cout << "Min eating speed " << min_eating_speed << std::endl;
        
    }
    {
        std::cout << std::endl << "Example 3" << std::endl;
        int available_hours = 6;
        std::vector<int> piles = {30,11,23,4,20};
        std::cout << "Piles: " ;
        dumpValues(piles);
        std::cout << "Hours available : " << available_hours << std::endl;
        int min_eating_speed = minEatingSpeed(piles,available_hours);
        std::cout << "Min eating speed " << min_eating_speed << std::endl;
        
    }
    return -1;
}
