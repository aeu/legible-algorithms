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
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>

std::pair<int,int> getNorth(std::pair<int,int> current, std::vector<std::vector<int>> &matrix)
{
    if( current.first == 0 )
        return std::make_pair(-1,-1);
    return std::make_pair(current.first-1,current.second);
}

std::pair<int,int> getSouth(std::pair<int,int> current, std::vector<std::vector<int>> &matrix)
{
    if( current.first == matrix.size()-1 )
        return std::make_pair(-1,-1);
    return std::make_pair(current.first+1,current.second);
}

std::pair<int,int> getEast(std::pair<int,int> current, std::vector<std::vector<int>> &matrix)
{
    if( current.second >= matrix[0].size()-1 )
    {
        return std::make_pair(-1,-1);
    }
    return std::make_pair(current.first,current.second+1);
}

std::pair<int,int> getWest(std::pair<int,int> current, std::vector<std::vector<int>> &matrix)
{
    if( current.second == 0 )
        return std::make_pair(-1,-1);
    return std::make_pair(current.first,current.second-1);
}

int valueAt(std::pair<int,int> coords, std::vector<std::vector<int>> &matrix )
{
    return matrix[coords.first][coords.second];
}

bool isValid(std::pair<int,int> coords)
{
    if(( coords.first == -1 ) || ( coords.second == -1 ))
        return false;
    return true;
}

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    std::set<std::pair<int,int>> visited;
    std::vector<int> retval;

    bool dead_end = false;
    std::pair<int,int> current = std::make_pair(0,0);
    std::pair<int,int> next;
    retval.push_back( valueAt( current,matrix));
    visited.insert( current );
    while( ! dead_end )
    {
        dead_end = true;
        next = getEast( current, matrix );
        while( ( isValid( next )) && ( visited.find( next ) == visited.end()  ))
        {
            int newval = valueAt( next, matrix );
            retval.push_back(newval );
            visited.insert( next );
            current = next;
            next = getEast( current, matrix );
            dead_end = false;
        }

        next = getSouth( current, matrix );
        while( ( isValid( next )) && ( visited.find( next ) == visited.end()  ))
        {
            int newval = valueAt( next, matrix );
            retval.push_back(newval );
            visited.insert( next );
            current = next;
            next = getSouth( current, matrix );
            dead_end = false;
        }
        next = getWest( current, matrix );
        while( ( isValid( next )) && ( visited.find( next ) == visited.end()  ))
        {
            int newval = valueAt( next, matrix );
            retval.push_back(newval );
            visited.insert( next );
            current = next;
            next = getWest( current, matrix );
            dead_end = false;
        }
        next = getNorth( current, matrix );
        while( ( isValid( next )) && ( visited.find( next ) == visited.end()  ))
        {
            int newval = valueAt( next, matrix );
            retval.push_back(newval );
            visited.insert( next );
            current = next;
            next = getNorth( current, matrix );
            dead_end = false;
        }
    }
    return retval;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix = { { 1,2,3 } , { 4,5,6} , { 7,8,9 }};
        std::vector<int> expected = { 1,2,3,6,9,8,7,4,5};
        std::vector<int> result   = spiralOrder(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix = { { 1,2,3,4 } , { 5,6,7,8} , { 9,10,11,12 }};
        std::vector<int> expected = { 1,2,3,4,8,12,11,10,9,5,6,7};
        std::vector<int> result   = spiralOrder(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
