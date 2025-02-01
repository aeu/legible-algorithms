// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>


void dumpValues(std::vector<int> values )
{
    bool first_time = true;
    std::cout << "[" ;
    for( int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
{
    int rooms_opened = 0;
    std::queue<int> keys;
    std::vector<bool> cleared_rooms( rooms.size(), false);
    keys.push(0);
    while( ! keys.empty() )
    {
        int current_key = keys.front();
        keys.pop();
        if( cleared_rooms[current_key] == false )
        {
            std::vector<int> current_room = rooms[current_key];
            rooms_opened++;
            for(int found_key : current_room )
            {
                keys.push(found_key);
            }
            cleared_rooms[current_key] = true;
        }
    }
    if( rooms_opened == rooms.size() )
        return true;
    return false;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #841 - Keys And Rooms" << std::endl;
    {
        std::vector<std::vector<int>> rooms = {{1},{2},{3},{}};
        bool can_visit = canVisitAllRooms(rooms);
        std::cout << "Can visit all rooms in [[1],[2],[3],[]] : " << ( can_visit ? "True" : "False" ) << std::endl;
    }
    {
        std::vector<std::vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
        bool can_visit = canVisitAllRooms(rooms);
        std::cout << "Can visit all rooms in [[1,3],[3,0,1],[2],[0]] : " << ( can_visit ? "True" : "False" ) << std::endl;
    }


    
    return -1;
}
