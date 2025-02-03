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

class Solution
{
public:
    
    double findMedianSortedArraysBruteForce(std::vector<int>& nums_one, std::vector<int>& nums_two)
    {
        std::vector<int>::iterator iter_one;
        std::vector<int>::iterator iter_two;
        
        iter_one = nums_one.begin();
        iter_two = nums_two.begin();

        int current = 0;
        int previous = 0;
        
        int total_numbers  = nums_one.size() + nums_two.size();
        int stopping_point  = total_numbers / 2;
        
        while(stopping_point >= 0 )
        {
            stopping_point--;
            previous = current;
            if( iter_one != nums_one.end() && iter_two != nums_two.end())
            {
                if( *iter_one <= *iter_two )
                {
                    current = *iter_one;
                    iter_one++;
                }
                else
                {
                    current = *iter_two;
                    iter_two++;
                }
            }
            else if( iter_one == nums_one.end() )
            {
                current = *iter_two;
                iter_two++;
            }
            else if( iter_two == nums_two.end() )
            {
                current = *iter_one;
                iter_one++;
            }
        }
        float retval;
        if( total_numbers & 1 )
        {
            retval = current;
        }
        else
        {
            retval = ( (float)current + (float)previous ) / 2.0;
        }
        return retval;
    }
};

int main(int argc, char **argv)
{
    printf("Leetcode #4: Median of two sorted arrays\n");

    Solution solver; //  = new Solution();
    
    {
        std::vector<int> array_one = {1,3,5};
        std::vector<int> array_two = {2,4};
        
        float median;
        printf("[1,3,5], [2,4]\n");
        median = solver.findMedianSortedArraysBruteForce( array_one, array_two );
        printf("median is %.2f\n", median );
    }
    
    {
        std::vector<int> array_one = { 1,2 };
        std::vector<int> array_two = { 3,4 };
        float median;
        printf("[1,2], [3,4]\n");
        median = solver.findMedianSortedArraysBruteForce( array_one, array_two );
        printf("median is %.2f\n", median );
    }
    
}
