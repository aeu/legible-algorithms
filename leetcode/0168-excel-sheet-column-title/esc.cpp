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

std::string convertToTitle(int columnNumber) 
{
    std::cout << "convert " << columnNumber  << std::endl;
    int scale = 26;
    int current = columnNumber;
    int rem = columnNumber % scale;
    std::string retval = "";
    while( current > 0 )
    {
        current--;
        rem = current % scale;
        char digit = 'A' + rem;
        retval = digit + retval;
        current = current / scale;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0168-excel-sheet-column-title" << std::endl << std::endl;
    int test_case = 1;
    {
        int columnNumber = 26;
        std::string expected = "Z";
        std::string result = convertToTitle(columnNumber);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int columnNumber = 1;
        std::string expected = "A";
        std::string result = convertToTitle(columnNumber);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int columnNumber = 28;
        std::string expected = "AB";
        std::string result = convertToTitle(columnNumber);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int columnNumber = 29;
        std::string expected = "AC";
        std::string result = convertToTitle(columnNumber);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int columnNumber = 701;
        std::string expected = "ZY";
        std::string result = convertToTitle(columnNumber);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
