// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>

bool isLeftClear(std::vector<int> &flowerbed,
                 const int current_position)
{
    if( current_position == 0 )
        return true;

    if( flowerbed[current_position-1] == 0 )
        return true;

    return false;
}

bool isRightClear(std::vector<int> &flowerbed,
                  const int current_position)
{
    if( current_position == ( flowerbed.size() - 1 ) )
        return true;

    if( flowerbed[current_position+1] == 0 )
        return true;

    return false;
}


bool canPlantFlowers(std::vector<int> &flowerbed,
                     const int goal_flowers)
{
    int flowers_planted = 0;
    for(int index = 0;index<(int)flowerbed.size();index++)
    {
        if( flowerbed[index] == 0 )
        {
            if( isLeftClear(flowerbed,index) && isRightClear(flowerbed,index))
            {
                flowers_planted++;
                flowerbed[index] = 1;
            }
        }
    }
    return flowers_planted >= goal_flowers;
}

int main(int argc, char **argv)
{
    {
        std::vector<int> flowerbed = { 1, 0, 0, 0, 1 };
        bool status = canPlantFlowers( flowerbed, 1 );
        printf("Can plant flowers - %s\n", ( status == true ) ? "true" : "false" );
    }
    {
        std::vector<int> flowerbed = { 1, 0, 0, 0, 1 };
        bool status = canPlantFlowers( flowerbed, 2 );
        printf("Can plant flowers - %s\n", ( status == true ) ? "true" : "false" );
    }
  
}
