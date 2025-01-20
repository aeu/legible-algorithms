// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

void dumpChars(const std::vector<char> &chars,
               const int stop_at = -1 )
{
    bool first_time = true;
    int chars_dumped = 0;
    for(char current : chars )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
        chars_dumped++;
        if( ( stop_at != -1 ) && ( chars_dumped > stop_at -1 ))
            break;
    }
    std::cout << std::endl;
}

int compress(std::vector<char>& chars)
{
    int running_size = 0;
    char previous;
    int running_count = 0;
    bool first_time = true;
    for(char current : chars )
    {
        if( first_time )
        {
            previous = current;
            running_count++;
        }
        else
        {
            if ( current == previous )
            {
                running_count++;
            }
            else
            {
                std::cout << "changed, we prev had " << previous << " as input with count : " << running_count << std::endl;
                std::string temp;
                temp += previous;
                if( running_count > 1 )
                {
                    temp += std::to_string(running_count);
                }
                for(char ccar : temp )
                {
                    chars[running_size++] = ccar;
                }
                previous = current;
                running_count = 1;
            }
        }
        first_time = false;
    }
    std::string temp;
    temp += previous;
    if( running_count > 1 )
    {
        temp += std::to_string(running_count);
    }
    for(char ccar : temp )
    {
        chars[running_size++] = ccar;
    }
    return running_size;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #443 - String Compression" << std::endl;
    {
        std::vector<char> chars = {'a','b','b','b','b','b','b'};
        std::cout << "Input  : ";
        dumpChars(chars);
        int size = compress(chars);
        std::cout << "Output n=" << size << " : ";
        dumpChars(chars,size);
    }
    {
    }
    return 1;
}
