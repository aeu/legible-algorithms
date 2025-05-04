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


// The algorithm for myAtoi(string s) is as follows:

// 1. Whitespace: Ignore any leading whitespace (" ").
// 2. Signedness: Determine the sign by checking if the next character
// is '-' or '+', assuming positivity if neither present.
// 3. Conversion: Read the integer by skipping leading zeros until a
// non-digit character is encountered or the end of the string is
// reached. If no digits were read, then the result is 0.
// 4. Rounding: If the integer is out of the 32-bit signed integer
// range [-231, 231 - 1], then round the integer to remain in the
// range. Specifically, integers less than -231 should be rounded to
// -231, and integers greater than 231 - 1 should be rounded to 231 -
// 1.


int myAtoi(char * s)
{
    int length = strlen(s);
    char *local = s;
    long long running = 0;
    int curpos = 0;
    bool is_negative = false;
    while( curpos < length )
    {
        // stage 1
        while( isspace( s[curpos] ))
        {
            curpos++;
            if( curpos >= length )
                break;
        }
        if( curpos >= length )
            break;
        
        // stage 2
        if(( s[curpos] == '-' ) || ( s[curpos] == '+' ))
        {
            // std::cout << "skipping a sign char" << std::endl;
            if( s[curpos] == '-' )
            {
                // std::cout << "\t which was negative" << std::endl;
                is_negative = true;
            }
            curpos++;
        }
        
        // stage 3
        while((curpos < length ) && ( s[curpos] == '0' ))
        {
            curpos++;
        }

        if( curpos >= length )
            break;
        
        while((curpos < length ) && ( isdigit( s[curpos] )))
        {
            running = running * 10 + (s[curpos] - '0');
            curpos++;
            if( running > (long long )INT_MAX )
                break;
        }
        if( running > (long long) INT_MAX )
            break;
        if( ! isdigit(s[curpos] ))
            break;
        curpos++;
    }
    // std::cout << "done, running is now " << running << std::endl;
    if( is_negative )
        running *= -1;

    if( running < (long long ) INT_MIN )
        return INT_MIN;
    if( running > (long long) INT_MAX )
        return INT_MAX;
    
    int retval = running;
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0008-string-to-integer" << std::endl << std::endl;
    int test_case = 1;
    {
        char s[] = "-91283472332";
        int result = myAtoi(s);
        int expected = -2147483648;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        char s[] = "42";
        int result = myAtoi(s);
        int expected = 42;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        char s[] = " -42";
        int result = myAtoi(s);
        int expected = -42;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        char s[] = "1337c0d3";
        int result = myAtoi(s);
        int expected = 1337;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        char s[] = "0-1";
        int result = myAtoi(s);
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        char s[] = "words and 987";
        int result = myAtoi(s);
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
