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
#include <stack>
#include <unordered_set>

void dumpNumbers(const std::vector<int> &numbers )
{
    bool first_time = true;
    std::cout << "[";
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}   

std::vector<int> aasteroidCollision(std::vector<int>& asteroids)
{
    std::vector<int> retval;
    bool done = false;
    for(int current : asteroids )
    {
        if( retval.size() == 0 )
        {
            retval.push_back(current);
            continue;
        }
        int previous = retval.back();
        if(( previous < 0 ) || (( previous * current ) > 0 ))
        {
            retval.push_back(current);
        }
        else
        {
            done = false;
            while( ! done )
            {
                if( previous < 0 )
                {
                    retval.push_back(current);
                    done = true;
                }
                else if( abs(previous) == abs(current))
                {
                    retval.pop_back();
                    done = true;
                }
                else if( abs(previous) > abs(current))
                {
                    done = true;
                }
                else
                {
                    retval.pop_back();
                    if( retval.size() == 0 )
                    {
                        retval.push_back(current);
                        done = true;
                    }
                    else
                    {
                        previous = retval.back();
                    }
                }
            }
        }
    }
    return retval;
}

bool oppositeSigns(int x, int y)
{
    if(( x < 0 ) && ( y > 0 ))
        return true;
    if(( y < 0 ) && ( x > 0 ))
        return true;
    return false;
}

std::vector<int> asteroidCollision(std::vector<int>& asteroids)
{
    std::stack<int> belt;
    for(const auto curr : asteroids )
    {
        int candidate = curr;
        bool complete = false;
        while( ! complete )
        {
            if( belt.empty() )
            {
                belt.push( candidate );
                complete = true;
            }
            else
            {
                int curfront = belt.top();
                if( oppositeSigns( curfront, candidate ) )
                {
                    if( abs(candidate) == abs(curfront) )
                    {
                        belt.pop();
                        complete = true;
                    }
                    else if( abs (candidate) > abs ( curfront ) )
                    {
                        belt.pop();
                    }
                    else
                    {
                        candidate = curfront;
                        belt.pop();
                    }
                }
                else
                {
                    belt.push( candidate );
                    complete = true;
                }
            }
        }
    }
    std::vector<int> retval;
    while( ! belt.empty() )
    {
        retval.push_back( belt.top() );
        belt.pop();
    }
    std::reverse(retval.begin(),retval.end());
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "Leetcode 0735 - Asteroid Collision" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> asteroids = { 5,10,-5 };
        std::vector<int> expected = { 5,10 };
        std::vector<int> result = asteroidCollision(asteroids);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> asteroids = { 8,-8 };
        std::vector<int> expected = { };
        std::vector<int> result = asteroidCollision(asteroids);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> asteroids = { 10,2,-5 };
        std::vector<int> expected = { 10 };
        std::vector<int> result = asteroidCollision(asteroids);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
