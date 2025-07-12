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

std::string intToRoman(int num)
{
    std::cout << "itr: " << num << std::endl;
    std::string retval;
    if( num > 3999 )
        return retval;

    int local = num;
    int lindex = 0;
    while( local > 0 )
    {
        if( local == 9 )
        {
            retval += "IX";
            local = 0;
        }
        else if( local >= lookups[lindex].second )
        {
            int rem = local / lookups[lindex].second;
            local = local - ( rem * lookups[lindex].second );
            std::cout << "rem: " << rem << " local " << local << std::endl;
            if( rem == 4 )
            {
                retval += lookups[lindex].first;
                retval += lookups[lindex-1].first;
            }
            else
            {
                while( rem > 0 )
                {
                    retval += lookups[lindex].first;
                    rem--;
                }
            }
        }
        else
        {
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
