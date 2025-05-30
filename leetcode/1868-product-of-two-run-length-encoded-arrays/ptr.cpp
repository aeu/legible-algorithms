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



std::vector<std::vector<int>> findRLEArray(std::vector<std::vector<int>>& encoded1,
                                           std::vector<std::vector<int>>& encoded2)
{
    std::vector<std::vector<int>> retval;

    std::vector<int> nums1;
    std::vector<int> nums2;

    for(const auto &curr : encoded1 )
    {
        int value = curr[0];
        int count = curr[1];
        while( count > 0 )
        {
            nums1.push_back(value);
            count--;
        }
    }
    
    for(const auto &curr : encoded2 )
    {
        int value = curr[0];
        int count = curr[1];
        while( count > 0 )
        {
            nums2.push_back(value);
            count--;
        }
    }
    dumpValues(nums1);
    dumpValues(nums2);

    for(int index=0;index<nums1.size();index++)
    {
        nums1[index] *= nums2[index];
    }
    dumpValues(nums1);

    int count = 1;
    int current = nums1[0];
    for(int index=1;index<nums1.size();index++)
    {
        if( nums1[index] == nums1[index-1] )
        {
            count++;
        }
        else
        {
            retval.push_back({nums1[index],count});
            std::cout << "pushing back " << nums1[index] << " - " << count << std::endl;
            count = 1;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1868-product-of-two-run-length-encoded-arrays" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> encoded1 = {{1,3},{2,3}};
        std::vector<std::vector<int>> encoded2 = {{6,3},{3,3}};
        std::vector<std::vector<int>> expected = {{6,6}};
        std::vector<std::vector<int>> result = findRLEArray(encoded1,encoded2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> encoded1 = {{1,3},{2,1},{3,2}};
        std::vector<std::vector<int>> encoded2 = {{2,3},{3,3}};
        std::vector<std::vector<int>> expected = {{2,3},{6,1},{9,2}};
        std::vector<std::vector<int>> result = findRLEArray(encoded1,encoded2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
