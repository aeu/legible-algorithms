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


// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000


std::vector<std::pair<std::string, int>> lookups = {
    { "M", 1000 },
    { "D", 500  },
    { "C", 100  },
    { "L", 50   },
    { "X", 10   },
    { "V", 5    },
    { "I", 1    }
};

int getFirstDigit(int num)
{
    int digit = 0;
    if( num >= 100 )
    {
        int remainder = num / 1000;
        int thousands = num - remainder;
        digit = thousands / 100;
    }
    else if ( num >= 10 )
    {
        int remainder = num / 100;
        int hundreds = num - remainder;
        digit = hundreds / 10;
    }
    else
    {
        digit = num;
    }
    return digit;
}

std::string intToRoman(int num)
{
    std::string retval;
    if( num > 3999 )
        return retval;

    for( auto curr_pair : lookups )
    {
        if( num == curr_pair.second)
            return curr_pair.first;
    }
    
    int local = num;
    int lindex = 0;

    while( local > 0 )
    {
        int first_digit = getFirstDigit( local );
        if( ( first_digit == 4 ) || ( first_digit == 9 ))
        {
            if( local >= 900 )
            {
                retval += "CM";
                local -= 900;
            }
            else if ( local >= 400 )
            {
                retval += "CD";
                local -= 400;
            }
            else if ( local >= 90 )
            {
                retval += "XC";
                local -= 90;
            }
            else if ( local >= 40 )
            {
                retval += "XL";
                local -= 40;
            }
            else if ( local == 9 )
            {
                retval += "IX";
                local -= 9;
            }
            else if ( local == 4 )
            {
                retval += "IV";
                local -= 4;
            }
        }
        else if( local >= lookups[lindex].second )
        {
            int count = local / lookups[lindex].second;
            local = local - ( count * lookups[lindex].second );
            if( count == 4 )
            {
                retval += lookups[lindex].first;
                retval += lookups[lindex-1].first;
            }
            else
            {
                while( count > 0 )
                {
                    retval += lookups[lindex].first;
                    count--;
                }
            }
        }
        lindex++;
    }
    
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0012-integer-to-romain" << std::endl << std::endl;
    int test_case = 1;
    {
        int num = 1000;
        std::string expected = "M";
        std::string result = intToRoman(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int num = 3749;
        std::string expected = "MMMDCCXLIX";
        std::string result = intToRoman(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int num = 58;
        std::string expected = "LVIII";
        std::string result = intToRoman(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int num = 1994;
        std::string expected = "MCMXCIV";
        std::string result = intToRoman(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
