// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>


void dumpHeights(std::vector<int> &heights)
{
    printf("[");
    bool first = true;
    for( auto current : heights )
    {
        if( ! first )
            printf(",");
        printf("%d", current );
        first = false;
    }
    printf("]\n");
}

int largestRectangleInHistogram(std::vector<int> &heights)
{
    dumpHeights(heights);
    std::vector<int>::iterator hiter;
    std::vector<int>::iterator left;
    std::vector<int>::iterator right;
    int heights_left_as_tall_as_me;
    int heights_right_as_tall_as_me;
    int test_height;
    int max_rectangle = 0;
    int current_rectangle;
    for( hiter = heights.begin(); hiter != heights.end(); hiter++)
    {
        heights_left_as_tall_as_me = 0;
        heights_right_as_tall_as_me = 0;
        test_height = *hiter;
        left = hiter;
        left--;
        while( left >= heights.begin() )
        {
            if( *left >= test_height )
                heights_left_as_tall_as_me++;
            else
                break;
            left--;
        }

        right = hiter;
        right++;
        while( right != heights.end() )
        {
            if( *right >= test_height )
                heights_right_as_tall_as_me++;
            else
                break;
            right++;
        }
        current_rectangle = test_height * ( heights_left_as_tall_as_me + heights_right_as_tall_as_me + 1 );
        if( current_rectangle > max_rectangle )
            max_rectangle = current_rectangle;
    }
    return max_rectangle;
}

int main(int argc, char **argv)
{
    printf("Leetcode 0084 - Largest Rectangle in Histogram\n");
    {
        std::vector<int> heights;
        heights.push_back( 2 );
        heights.push_back( 1 );
        heights.push_back( 5 );
        heights.push_back( 6 );
        heights.push_back( 2 );
        heights.push_back( 3 );
        
        int largest_rectangle = largestRectangleInHistogram( heights );
        printf("largest_rectangle: %d\n", largest_rectangle );

    }
    {
        std::vector<int> heights;
        heights.push_back( 2 );
        heights.push_back( 4 );
        
        int largest_rectangle = largestRectangleInHistogram( heights );
        printf("largest_rectangle: %d\n", largest_rectangle );
    }
}
