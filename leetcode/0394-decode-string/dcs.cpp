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
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>

std::string processSegment(std::string candidate,
                           int start_point)
{
    std::string retval;
    char current;
    for(int index=start_point;index<candidate.length();index++)
    {
        current = candidate[index];
        if( ( current != '[' ) && ( current != ']' ))
        {
            retval += current;
        }
        else if( current == '[' )
        {
            char last_char;
            bool done = false;
            std::string multiplier = "";
            std::string subsegment = processSegment(candidate, index+1);
            while( ! retval.empty() && ! done )
            {
                last_char = retval.back();
                if( isdigit( last_char ))
                {
                    retval.pop_back();
                    std::string last_str(1,last_char);
                    multiplier.insert(0,last_str);
                }
                else
                {
                    done = true;
                }
            }
            if( ! multiplier.empty() )
            {
                int multiplier_as_int = atoi( multiplier.c_str());
                while( multiplier_as_int > 0 )
                {
                    retval += subsegment;
                    multiplier_as_int--;
                }
            }
            index += subsegment.length()+1;
        }
        else if( current == ']' )
            break;
    }
    return retval;
}


//    std::string retval;
//    retval += processSegment(candidate,0);
//    return retval;


std::string decodeString(std::string candidate)
{
    std::stack<int> multipliers;
    std::stack<std::string> strings;
    std::string current_string;
    int multiplier = 0;
    for(const auto curr : candidate )
    {
        if( isdigit(curr) )
        {
            multiplier = multiplier * 10 + ( curr - '0' ) ;
        }
        else if( curr == '[' )
        {
            multipliers.push( multiplier );
            strings.push(current_string);
            current_string.clear();
            multiplier = 0;
        }
        else if( curr == ']' )
        {
            int repeat_count = multipliers.top();
            multipliers.pop();
            std::string previous = strings.top();
            strings.pop();

            std::string repeated;
            while( repeat_count > 0 )
            {
                repeated += current_string;
                repeat_count--;
            }
            current_string = previous + repeated;
        }
        else
        {
            current_string += curr;
        }
    }
    return current_string;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0394 - Decode String" << std::endl;
    int test_case = 1;
    {
        std::string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
        std::string expected = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
        std::string result = decodeString(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "3[a]2[bc]";
        std::string expected = "aaabcbc";
        std::string result = decodeString(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "3[a2[c]]";
        std::string expected = "accaccacc";
        std::string result = decodeString(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "2[abc]3[cd]ef";
        std::string expected = "abcabccdcdcdef";
        std::string result = decodeString(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
