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

std::string removeStars(std::string &s)
{
    std::string retval;
    for(char current : s )
    {
        if( current != '*' )
        {
            retval.push_back(current);
        }
        else
        {
            if( retval.length() > 0 )
            {
                retval.pop_back();
            }
        }
    }
    return retval;
}
int main(int argc, char **argv)
{
    std::cout << "Leetcode 2390 - Removing stars from a string" << std::endl;
    {
        std::string before = "leet**cod*e";
        std::string after = removeStars(before);
        std::cout << "Before : " << before << " after: " << after << std::endl;
    } 
    {
        std::string before = "erase*****";
        std::string after = removeStars(before);
        std::cout << "Before : " << before << " after: " << after << std::endl;
    }
}
