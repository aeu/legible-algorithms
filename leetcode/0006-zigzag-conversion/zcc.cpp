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

std::string convert(std::string s, int numRows) 
{
    if( numRows == 1 )
        return s;
    std::vector<std::string> rows(numRows, "");
    std::string retval;
    bool direction = true;
    int index = 0;
    for(const char curr : s )
    {
        rows[index] += curr;
        if( direction )
            index++;
        else
            index--;

        if( index == numRows )
        {
            direction = ! direction;
            index = index-2;
        }
        else if ( index < 0 )
        {
            direction = !direction;
            index=1;
        }
    }
    for(const auto curr : rows )
    {
        retval += curr;
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0006-zigzag-conversion" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "AB";
        int numRows = 1;
        std::string result = convert(s,numRows);
        std::string expected = "AB";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 3;
        std::string result = convert(s,numRows);
        std::string expected = "PAHNAPLSIIGYIR";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 4;
        std::string result = convert(s,numRows);
        std::string expected = "PINALSIGYAHRPI";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "A";
        int numRows = 1;
        std::string result = convert(s,numRows);
        std::string expected = "A";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
