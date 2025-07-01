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

int myAtoi(std::string s)
{
    long retval = 0;
    const char *current = s.c_str();
    int sign = 1;
    bool started_number = false;
    int was_digit = 0;
    int done = 0;
    char previous;
    
    while( *current != 0 && ! done )
    {
        // per requirement #5
        // If the integer is out of the 32-bit signed integer range
        // [-2^31, 2^31 - 1], then clamp the integer so that it remains
        // in the range. Specifically, integers less than -2^31 should
        // be clamped to -2^31, and integers greater than 231 - 1
        // should be clamped to 2^31 - 1.
        
        if( retval >= INT_MAX )
        {
            if( sign == -1 )
                return -INT_MAX;
            else
                return INT_MAX;
        }
        
        switch( *current )
        {
        case '0':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            was_digit = 1;
            retval *= 10;
            break;
        case '1':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 1;
            break;
        case '2':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 2;
            break;
        case '3':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 3;
            break;
        case '4':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 4;
            break;
        case '5':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 5;
            break;
        case '6':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 6;
            break;
        case '7':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 7;
            break;
        case '8':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 8;
            break;
        case '9':
            if( ! started_number && previous == '-' )
                sign = -1;
            started_number = true;
            retval *= 10;
            retval += 9;
            break;
        default:
            if( started_number )
                done = 1;
            break;
        }
        previous = *current;
        current++;
    }

    retval *= sign;
    return retval;
}

int main(int argc, char **argv)
{
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("     -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("asdf- 4193 with other words"));
    printf("%d\n", myAtoi("asdf-4193 with other words"));
    printf("%d\n", myAtoi("adsf8798798798798798797 with words 3434"));
    printf("%d\n", myAtoi("adsf-238798798798798798797 with words 3434"));
}
