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

// we know that if the numrows is N, then the grid is going to be s.length / 3.
// we know that if the numrows is 3, the gap between the 


std::string convert(std::string s, int numRows)
{
    std::string retval = "";
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0006-zigzag-conversion" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 3;
        std::string expected = "PAHMAPLSIIGYIR";
        std::string result = convert(s,numRows);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "PAYPALISHIRING";
        int numRows = 4;
        std::string expected = "PINALSIGYAHRPI";
        std::string result = convert(s,numRows);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "A";
        int numRows = 1;
        std::string expected = "A";
        std::string result = convert(s,numRows);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
