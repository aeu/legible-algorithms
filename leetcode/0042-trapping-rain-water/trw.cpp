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

class Solution
{
    private:
    protected:

    int highestToMyLeft(std::vector<int>& values,
                         std::vector<int>::iterator curpos )
    {
        int retval = 0;
        while( curpos != values.begin() )
        {
            curpos--;
            int current = (int)*curpos;
            if( current > retval )
                retval = current;
        }
        return retval;
    }

    int highestToMyRight(std::vector<int>& values,
                          std::vector<int>::iterator curpos )
    {
        int retval = 0;
        while( curpos != values.end() )
        {
            curpos++;
            int current = (int)*curpos;
            if( current > retval )
                retval = current;
        }
        return retval;
    }

    public:
    int trap(std::vector<int>& height)
    {
        int retval = 0;
        int current;
        std::vector<int>::iterator hiter;
        for(hiter =  height.begin();
            hiter != height.end();
            hiter++)
        {
            current = (int)*hiter;
            int left_high = this->highestToMyLeft(height, hiter);
            int right_high = this->highestToMyRight(height, hiter);
            int max_possible = std::min( left_high, right_high );
            if( max_possible > current )
                retval += max_possible - current;
            
        }
        return retval;
    }
    
};

int main(int argc, char **argv)
{
    printf("Leetcode #42: Trapping Rain Water\n");

    Solution *solver = new Solution();
    {
        std::vector<int> heights;
        heights.push_back(0);
        heights.push_back(1);
        heights.push_back(0);
        heights.push_back(2);
        heights.push_back(1);
        heights.push_back(0);
        heights.push_back(1);
        heights.push_back(3);
        heights.push_back(2);
        heights.push_back(1);
        heights.push_back(2);
        heights.push_back(1);
        
        int answer = solver->trap( heights );
        printf("trapped amount is %d\n", answer );
    }
    {
        std::vector<int> heights;
        heights.push_back(4);
        heights.push_back(2);
        heights.push_back(0);
        heights.push_back(3);
        heights.push_back(2);
        heights.push_back(5);
        
        int answer = solver->trap( heights );
        printf("trapped amount is %d\n", answer );
    }
}
