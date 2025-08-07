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
#include <sstream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int compareVersion(std::string version1, std::string version2) 
{
    std::vector<int> v1;
    std::vector<int> v2;

    std::stringstream v1ss( version1 );
    std::string part;
    while( std::getline( v1ss, part, '.'))
    {
        v1.push_back( std::stoi( part ));
    }

    std::stringstream v2ss( version2 );
    while( std::getline( v2ss, part, '.'))
    {
        v2.push_back( std::stoi( part ));
    }

    int most = std::max( v1.size(), v2.size());
    for(int index = 0; index < most;index++)
    {
        int one_val;
        int two_val;
        if( index < v1.size())
            one_val = v1[index];
        else
            one_val = 0;
        
        if( index < v2.size())
            two_val = v2[index];
        else
            two_val = 0;

        if( one_val < two_val )
            return -1;
        else if( one_val > two_val )
            return 1;
    }
    return 0;    
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0165-compare-version-numbers" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string version1 = "1.2";
        std::string version2 = "1.10";
        int expected = -1;
        int result = compareVersion(version1,version2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string version1 = "1.01";
        std::string version2 = "1.001";
        int expected = 0;
        int result = compareVersion(version1,version2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string version1 = "1.0";
        std::string version2 = "1.0.0.0.0";
        int expected = 0;
        int result = compareVersion(version1,version2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
