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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int findKthPositive(std::vector<int> &arr, int k )
{
    int largest = arr.back();
    std::vector<int> hits(1000,0);
    for( const auto &curr : arr )
    {
        hits[curr] = 1;
    }
    int seek = k;
    for(int index=0;index<hits.size();index++)
    {
        std::cout << "[" << index << "] " << hits[index] << std::endl;
        if( hits[index] == 0 )
            seek--;
        if( seek == 0 )
            return index+1;
    }
    return 0;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1539-kth-missing-positive-number" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> arr = {2,3,4,7,11};
        int k = 5;
        int expected = 9;
        int result = findKthPositive(arr, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr = {1,2,3,4};
        int k = 2;
        int expected = 6;
        int result = findKthPositive(arr, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
