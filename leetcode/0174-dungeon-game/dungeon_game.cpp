// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <algorithm>
#include <vector>
#include <stdio.h>


typedef struct {
    int x;
    int y;
} Position;

int final_health = 9999;

int valueForPosition(std::vector<std::vector<int> > &dungeon,
                     Position position )
{
    auto row = dungeon[position.y];
    auto value = row[position.x];
    return value;
}

void dumpPath(std::vector<char> path)
{
    bool first_time = true;
    for(auto step : path )
    {
        if( first_time )
            first_time = false;
        else
            printf("-> ");
        if( step == 'r' )
            printf("RIGHT");
        else
            printf("DOWN");
    }
    printf("\n");
}


int healthForPath(std::vector<std::vector<int> > &dungeon,
                  std::vector<char> path)
{
    Position current_position = { 0, 0 };
    bool survived = false;
    int current_health = 0;
    int starting_health = 1;
    while( survived == false )
    {
        current_health = starting_health;
        current_health += valueForPosition( dungeon, current_position );
        if( current_health <= 0 )
        {
            starting_health++;
            current_position.x = 0;
            current_position.y = 0;
            continue;
        }
        for(auto current_direction : path )
        {
            if( current_direction == 'r' )
            {
                current_position.x++;
            }
            else
            {
                current_position.y++;
            }
            current_health += valueForPosition( dungeon, current_position );
            if( current_health <= 0 )
            {
                starting_health++;
                current_position.x = 0;
                current_position.y = 0;
                break;
            }
        }
        if( current_health > 0 )
        {
            survived = true;
        }
    }
    return starting_health;
}

void generateAndTraversePaths(std::vector<std::vector<int> > &dungeon,
                              std::vector<char> &path,
                              int size )
{
    if( size == 1 )
    {
        int health_needed_to_survive = healthForPath(dungeon, path );
        if( health_needed_to_survive < final_health )
        {
            final_health = health_needed_to_survive;
        }
    }
    else
    {
        for(int index=0;index<size;index++)
        {
            generateAndTraversePaths( dungeon, path, size-1 );
            if( size & 1 )
            {
                std::swap( path[0], path[size-1]);
            }
            else
            {
                std::swap( path[index], path[size-1]);
            }
        }
    }
}


void dumpDungeon(std::vector<std::vector<int> > &dungeon )
{
    for(auto current_row : dungeon )
    {
        bool first_time = true;
        printf("[");
        for(auto current_room : current_row )
        {
            if( first_time )
                first_time = false;
            else
            {
                printf(", ");
            }
            printf("%d", current_room );
        }
        printf("]\n");
    }       
}


int calculateMinimumInitialHealth(std::vector<std::vector<int> > &dungeon )
{
    final_health = 9999;
    int dungeon_size = dungeon[0].size();

    // handle the special case of a 1x1 dungeon
    if( dungeon_size == 1 )
    {
        Position one;
        one.x = 0;
        one.y = 0;
        int one_square = valueForPosition( dungeon, one );
        if( one_square >= 0 )
            final_health = 1;
        else
            final_health = abs( one_square ) + 1;
        return 1;
    }
    std::vector<char> base_path;
    for(int index=0;index<dungeon_size-1;index++)
    {
        base_path.push_back('r');
        base_path.push_back('d');
    }
    generateAndTraversePaths( dungeon, base_path, (int)base_path.size() );
    return 1;
}


int main(int argc, char **argv)
{
    { 
        std::vector<std::vector<int> > dungeon = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 }};
        printf("Given the following dungeon:\n");
        dumpDungeon( dungeon );
        calculateMinimumInitialHealth( dungeon );
        printf("Minimum initial health to traverse the dungeon is %d\n", final_health);
    }
    { 
        std::vector<std::vector<int> > dungeon = { { 0 } };
        printf("Given the following dungeon:\n");
        dumpDungeon( dungeon );
        calculateMinimumInitialHealth( dungeon );
        printf("Minimum initial health to traverse the dungeon is %d\n", final_health);
    }

    return -1;
}
