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
    
    double findMedianSortedArrays(std::vector<int>& nums_one, std::vector<int>& nums_two)
    {
        std::vector<int>::iterator iter_one;
        std::vector<int>::iterator iter_two;
        
        iter_one = nums_one.begin();
        iter_two = nums_two.begin();

        int current = 0;
        int previous = 0;
        
        int current_num_one;
        int current_num_two;

        int total_numbers  = nums_one.size() + nums_two.size();
        int stopping_point = ceil((float)total_numbers / 2 );


        int stopper = 0;
        int done = 0;
        while( ! done )
        {
            stopper++;
            if( iter_one == nums_one.end() )
                current_num_one = INT_MIN;
            else
                current_num_one = (int)*iter_one;


            if( iter_two == nums_two.end() )
                current_num_two = INT_MIN;
            else
                current_num_two = (int)*iter_two;

            if(( current_num_one == INT_MIN ) && ( current_num_two != INT_MIN ))
            {
                previous = current;
                current = current_num_two;
                iter_two++;
            }
            else if(( current_num_one != INT_MIN ) && ( current_num_two == INT_MIN ))
            {
                previous = current;
                current = current_num_one;
                iter_one++;
            }
            else if( current_num_one <= current_num_two )
            {
                previous = current;
                current = current_num_one;
                iter_one++;
            }
            else if ( current_num_one > current_num_two )
            {
                previous = current;
                current = current_num_two;
                iter_two++;
            }

            if ( stopper > stopping_point )
                done = 1;
        }

        float retval;
        if( total_numbers & 1 )
            retval = previous;
        else
            retval = ( (float)current + (float)previous ) / 2.0;

        return retval;
        
    }
};

int main(int argc, char **argv)
{
    printf("Leetcode #4: Median of two sorted arrays\n");

    Solution *solver = new Solution();
    
    {
        std::vector<int> array_one;
        std::vector<int> array_two;
        array_one.push_back(1);
        array_one.push_back(3);
        
        array_two.push_back(2);
        
        float median;
        printf("[1,3], [2]\n");
        median = solver->findMedianSortedArrays( array_one, array_two );
        printf("median is %.2f\n", median );
    }
    
    {
        std::vector<int> array_one;
        std::vector<int> array_two;
        array_one.push_back(1);
        array_one.push_back(2);
        
        array_two.push_back(3);
        array_two.push_back(4);
        
        float median;
        printf("[1,2], [3,4]\n");
        median = solver->findMedianSortedArrays( array_one, array_two );
        printf("median is %.2f\n", median );
    }
    
}
