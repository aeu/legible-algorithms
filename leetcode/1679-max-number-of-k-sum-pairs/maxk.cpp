// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


void dumpNumbers(const std::vector<int> &numbers)
{
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << std::endl;
}

int maxNumberOfKSumPairs(std::vector<int> &numbers,
                         const int k_value)
{
    std::sort(numbers.begin(), numbers.end());
    std::vector<int>::iterator low_side = numbers.begin();
    std::vector<int>::iterator high_side = numbers.end() - 1;
    int max_pairs = 0;
    while( low_side < high_side )
    {
        if(( *low_side + *high_side == k_value ))
        {
            max_pairs++;
            low_side++;
            high_side--;
            continue;
        }
        else if(( *low_side + *high_side < k_value ))
        {
            low_side++;
            continue;
        }
        else
        {
            high_side--;
            continue;
        }
    }
    return max_pairs;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1679 - Max Number of K-Sum Pairs" << std::endl << std::endl;
    {
        std::vector<int> numbers = { 1,2,3,4 };
        dumpNumbers(numbers);
        int max_ksum = maxNumberOfKSumPairs( numbers, 5 );
        std::cout << "Max number of KSum Pairs : " << max_ksum << std::endl;
        
    }
    {
        std::vector<int> numbers = { 3,1,3,4,3 };
        dumpNumbers(numbers);
        int max_ksum = maxNumberOfKSumPairs( numbers, 6 );
        std::cout << "Max number of KSum Pairs : " << max_ksum << std::endl;
        
    }
}
