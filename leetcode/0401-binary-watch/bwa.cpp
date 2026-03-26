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
#include <cstdio>
#include <limits.h>

std::string toString(int value)
{
    char buf[256];
    int hours = 0;
    int minutes = 0;
    if( value & 1 )
        minutes += 1;
    if ( value & 2 )
        minutes += 2;
    if ( value & 4 )
        minutes += 4;
    if ( value & 8 )
        minutes += 8;
    if ( value & 16 )
        minutes += 16;
    if ( value & 32 )
        minutes += 32;
    if  (value & 64 )
        hours += 1;
    if (value & 128)
        hours += 2;
    if ( value & 256)
        hours += 4;
    if (value & 512 )
        hours += 8;

    if(( hours < 12 ) && ( minutes <= 59 ))
    {
        snprintf(buf,256,"%d:%02d",hours,minutes);
        std::string timeAsString(buf);
        return timeAsString;
    }
    return "";
}

std::vector<std::string> readBinaryWatch(int turnedOn)
{
    std::vector<std::string> results;
    for(int mask = 0;mask<(1<<10);mask++)
    {
        int num_bits = 0;
        for(int count = 0;count<10;count++)
        {
            if( mask & ( 1 << count ) )
                num_bits++;
        }
        if( num_bits == turnedOn )
        {
            std::string current_time = toString(mask);
            if ( !current_time.empty())
                results.push_back(current_time);
        }
    }
    return results;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0401-binary-watch" << std::endl << std::endl;
    int test_case = 1;
    {
        int turnedOn = 1;
        std::vector<std::string> result = readBinaryWatch(turnedOn);
        std::vector<std::string> expected = { "0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00" };
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int turnedOn = 9;
        std::vector<std::string> result = readBinaryWatch(turnedOn);
        std::vector<std::string> expected = {};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
