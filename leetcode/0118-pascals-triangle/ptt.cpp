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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int doWork()
{
    return 1;
}


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for( const auto &curr : values )
    {
        if( ! first )
            std::cout << ", " ;
        first = false;
        std::cout << curr;
    }
    std::cout << std::endl;
}

std::vector<int> buildRow(std::vector<int> base)
{
    std::vector<int> retval;
    int index = 1;
    retval.push_back(1);
    while( index < base.size() )
    {
        retval.push_back( base[index-1] + base[index] );
        index++;
    }
    retval.push_back(1);
    return retval;
}

std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> retval;

    if( numRows == 0 )
        return retval;
    retval.push_back( {1} );
    if( numRows == 1 )
        return retval;
    retval.push_back( {1,1} );
    if( numRows == 2 )
        return retval;
    int togo = numRows - 2;
    while( togo > 0 )
    {
        std::vector<int> next_row = buildRow( retval.back() );
        retval.push_back(next_row);
        togo--;
    }
    return retval;
}
int main(int argc, char **argv)
{
    std::cout << std::endl << "0118-pascals-triangle" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> retval = generate(5);
        for(const auto &curr : retval )
        {
            dumpValues(curr);
        }
    }
    {
        std::vector<std::vector<int>> retval = generate(1);
        for(const auto &curr : retval )
        {
            dumpValues(curr);
        }
    }
    return 0;
}
