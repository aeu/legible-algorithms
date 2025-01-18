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

std::vector<int> asteroidCollision(std::vector<int>& asteroids)
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
int main(int argc, char **argv)
{
    std::cout << "Leetcode 0735 - Asteroid Collision" << std::endl;
    {
        std::vector<int> asteroids = { 5,10,-5 };
        std::vector<int> after = asteroidCollision(asteroids);
        dumpNumbers(asteroids);
        dumpNumbers(after);
    }
    {
        std::vector<int> asteroids = { 8,-8 };
        std::vector<int> after = asteroidCollision(asteroids);
        dumpNumbers(asteroids);
        dumpNumbers(after);
    }
    {
        std::vector<int> asteroids = { 10,2,-5 };
        std::vector<int> after = asteroidCollision(asteroids);
        dumpNumbers(asteroids);
        dumpNumbers(after);
    }
}
