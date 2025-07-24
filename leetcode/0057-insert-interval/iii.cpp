// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

void dumpPair(std::vector<int> pair)
{
    std::cout << "[" << pair[0] << "," << pair[1] << "]" ;
}

bool overlaps(std::vector<int> first, std::vector<int> second)
{
    if( (second[0] >= first[0]) && ((second[0]) <= first[1]))
    {
        return true;
    }
    if( (first[0] >= second[0]) && ((first[0]) <= second[1]))
    {
        return true;
    }
    return false;
}

std::vector<int> merge(std::vector<int> first, 
                       std::vector<int> second)
{
    std::vector<int> retval;
    retval.push_back( std::min( first[0], second[0]));
    retval.push_back( std::max( first[1], second[1]));
    return retval;
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, 
                                     std::vector<int>& newInterval) 
{
    std::vector<std::vector<int>> retval;
    if( intervals.size() == 0 )
    {
        retval.push_back( newInterval );
        return retval;
    }
    
    bool new_was_inserted = false;
    int index = 0;
    while( index < intervals.size() )
    {
        std::vector<int> *insertion_candidate;
        if(( new_was_inserted == false ) && ( newInterval[0] < intervals[index][0] ))
        {
            insertion_candidate = &newInterval;
            new_was_inserted = true;
        }
        else
        {
            insertion_candidate = &(intervals[index]);
            index++;
        }
        if( retval.empty())
        {
            retval.push_back( *insertion_candidate );
        }
        else
        {
            std::vector<int> &last = retval.back();
            if( overlaps( last, *insertion_candidate ))
            {
                std::vector<int> merged = merge( last, *insertion_candidate );
                retval.pop_back();
                retval.push_back( merged );
            }
            else
            {
                retval.push_back( *insertion_candidate );
            }
        }
    }
    if( new_was_inserted == false )
    {
        std::vector<int> &last = retval.back();
        if( overlaps( last, newInterval ))
        {
            std::vector<int> merged = merge( last, newInterval );
            retval.pop_back();
            retval.push_back( merged );
        }
        else
        {
            retval.push_back( newInterval );
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0057-insert-interval" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> intervals = {{1,5}};
        std::vector<int> newInterval = { 2, 7 };
        std::vector<std::vector<int>> mints = insert( intervals, newInterval );
        std::cout << "[" ;
        bool first_time = true;
        for(const auto &curr : mints )
        {
            if( ! first_time )
                std::cout << std::endl;
            first_time = false;
            dumpPair(curr);
        }
        std::cout << "]" ;
        int result = 0;
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> intervals = {{1,3},{6,9}};
        std::vector<int> newInterval = { 2,5 };
        std::vector<std::vector<int>> mints = insert( intervals, newInterval );
        std::cout << "[" ;
        bool first_time = true;
        for(const auto &curr : mints )
        {
            if( ! first_time )
                std::cout << std::endl;
            first_time = false;
            dumpPair(curr);
        }
        std::cout << "]" ;
        int result = 0;
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        std::vector<int> newInterval = { 4, 8 };
        std::vector<std::vector<int>> mints = insert( intervals, newInterval );
        std::cout << "[" ;
        bool first_time = true;
        for(const auto &curr : mints )
        {
            if( ! first_time )
                std::cout << std::endl;
            first_time = false;
            dumpPair(curr);
        }
        std::cout << "]" ;
        int result = 0;
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
