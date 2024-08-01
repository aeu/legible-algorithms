// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>


void distributeCandy(std::vector<int> ratings)
{
    int total_candies = ratings.size();

    printf("ratings: [");
    for(size_t index=0;index<ratings.size();index++)
    {
        int current = ratings.at(index);
        int left_neighbour = current;
        int right_neighbour = current;

        printf("%d ", current );
        
        if( index > 0 )
            left_neighbour = ratings.at(index-1);
        if( index < ratings.size() -1 )
            right_neighbour = ratings.at(index+1);

        if(( current > left_neighbour ) || ( current > right_neighbour ))
        {
            total_candies++;
        }
    }
    printf("]\n");
    printf("candies needed: %d\n\n", total_candies );
}

int main(int argc, char **argv)
{
    printf("Leetcode #0135 - Candy\n\n");
    {
        std::vector<int> ratings = { 1, 0, 2 };
        distributeCandy(ratings);
    }
    {
        std::vector<int> ratings = { 1, 2, 2 };
        distributeCandy(ratings);
    }
}
