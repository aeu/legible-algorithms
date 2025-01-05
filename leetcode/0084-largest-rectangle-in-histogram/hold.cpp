// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>
#include <stack>


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


int largestRectangleInHistogramBruteForce(std::vector<int> &heights)
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

int largestRectangleInHistogram(std::vector<int> &heights)
{
    int max_area = 0;
    std::stack<int> hstack;
    dumpHeights(heights);
    for(int index=0;index<(int)heights.size();index++)
    {
        printf("On pass #%d\n", index );
        if(( hstack.empty() )
           || ( heights[index] >= heights[hstack.top()]))
        {
            printf("\tStack empty, or next height (%d) is same or taller\n", heights[index]);
            printf("\tPushing %d on to the stack\n", index );
            hstack.push( index );
        }
        else
        {
            printf("\tnext height (%d) was lower, so popping\n", heights[index]);
            int current = hstack.top();
            hstack.pop();
            int width = hstack.empty() ? 1 : index - hstack.top() - 1;
            int area = heights[current] * width;
            max_area = std::max( max_area, area );
            printf("\tWidth: %d, height: %d, area : %d, new max_area: %d\n", width, heights[current], area, max_area );
            printf("\tPushing %d on to the stack\n", index );
            hstack.push(index);
        }
    }

    printf("ending stack\n");
    while(  ! hstack.empty() )
    {
        printf("%d\n", hstack.top());
        hstack.pop();
    }
    
    return 0;
}


#if 0
 while (!s.empty()) {
        int top_of_stack = s.top();
        s.pop();
        int area = heights[top_of_stack] * (s.empty() ? index : index - s.top() - 1);
        max_area = std::max(max_area, area);
    }
#endif


int main(int argc, char **argv)
{
    printf("Leetcode 0084 - Largest Rectangle in Histogram\n\n");
    {
        std::vector<int> heights = { 2,1,5,6,2,3};
        int largest_rectangle = largestRectangleInHistogram( heights );
        printf("largest_rectangle: %d\n\n", largest_rectangle );

    }
    return 0;
    {
        std::vector<int> heights = { 2, 4 }; 
        int largest_rectangle = largestRectangleInHistogramBruteForce( heights );
        printf("largest_rectangle: %d\n\n", largest_rectangle );
    }
}
