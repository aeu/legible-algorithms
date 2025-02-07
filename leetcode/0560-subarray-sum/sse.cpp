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


void dumpValues(const std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int subarraySum(std::vector<int> &sums, int k )
{
    std::map<int,int> prefix_sums;
    int running_sum = 0;
    int subarray_sums = 0;
    prefix_sums[0]++;
    for(int current : sums )
    {
        running_sum += current;
        int prefix_sum = running_sum - k;
        std::map<int,int>::iterator ps_iter;
        ps_iter = prefix_sums.find( prefix_sum );
        if( ps_iter != prefix_sums.end())
        {
            int prefix_sum_count = ps_iter->second;
            subarray_sums += prefix_sum_count;
        }
        prefix_sums[running_sum]++;
    }
    return subarray_sums;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0560 - Subarray Sum Equals K" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        int k = 2;
        std::vector<int> sums = { 1,1,1 };
        std::cout << "Values: " ;
        dumpValues(sums);
        int sas = subarraySum(sums,k);
        std::cout << "Subarray Sums: " << sas << std::endl;
    }
    {
        std::cout << "Example 2" << std::endl; 
        int k = 3;
        std::vector<int> sums = { 1,2,3 };
        std::cout << "Values: " ;
        dumpValues(sums);
        int sas = subarraySum(sums,k);
        std::cout << "Subarray Sums: " << sas << std::endl;
    }
}
