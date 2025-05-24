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
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

bool isStrobogrammatic(std::string num)
{
    std::string local = num;
    std::reverse(local.begin(),local.end());
    for(int index=0;index<local.length();index++)
    {
        char lchar = local[index];
        char nchar = num[index];
        if( ! isdigit( lchar ) )
            return false;

        if( lchar == '0' && nchar == '0' )
        {
        }
        else if( lchar == '8' && nchar == '8' )
        {
        }
        else if( lchar == '6' && nchar == '9' )
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string num = "69";
        bool expected = true;
        bool result = isStrobogrammatic(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string num = "88";
        bool expected = true;
        bool result = isStrobogrammatic(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string num = "962";
        bool expected = false;
        bool result = isStrobogrammatic(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
