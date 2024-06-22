// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <string>
#include <stdio.h>

void doWork(std::string haystack,
           std::string needle )
{
    printf("Searching for %s in %s\n", needle.c_str(), haystack.c_str());
    std::string sorted_needle = needle;
    sort( sorted_needle.begin(), sorted_needle.end());
    if( needle.length() > haystack.length() )
    {
        printf("\tCandidate %s is too long to fit in %s\n", needle.c_str(), haystack.c_str());
        return;
    }
    
    bool done = true;
    std::string::iterator substring_begin = haystack.begin();
    int current_length = needle.length();
    int start_index = 0;

    if(( start_index + current_length ) <= haystack.length())
        done = false;

    while ( ! done )
    {
        std::string substring = haystack.substr( start_index, current_length );
        std::string sorted_substring = substring;
        sort( sorted_substring.begin(), sorted_substring.end() );
        auto spos = sorted_substring.find( sorted_needle );
        if( spos != std::string::npos )
        {
            printf("\t%s was found in %s\n", needle.c_str(), substring.c_str() );
            done = true;
        }
        start_index++;
        if(( start_index + current_length ) > haystack.length())
        {
            start_index = 0;
            current_length++;
        }
        if(( start_index + current_length ) > haystack.length())
        {
            done = true;
        }
    }
}



int main(int argc, char **argv)
{
    doWork("ADOBECODEBANC", "ABC");
    doWork("a", "a");
    doWork("a", "aa");
}
