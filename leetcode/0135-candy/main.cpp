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
    std::vector<int>::iterator rating_iterator;
    
    for(size_t index=0;index<ratings.size();index++)
    {
        printf("current rating %d\n", ratings.at(index));
        int current = ratings.at(index);
        int left_neighbour = current;
        int right_neighbour = current;

        if( index > 0 )
            left_neighbour = ratings.at(index-1);
        if( index < ratings.size() -1 )
            right_neighbour = ratings.at(index+1);

        if(( current > left_neighbour ) || ( current > right_neighbour ))
        {
            total_candies++;
        }
    }
        printf("candies: %d\n", total_candies );
}

int main(int argc, char **argv)
{
    {
        std::vector<int> ratings = { 1, 0, 2 };
        distributeCandy(ratings);
    }
    {
        std::vector<int> ratings = { 1, 2, 2 };
        distributeCandy(ratings);
    }
}
