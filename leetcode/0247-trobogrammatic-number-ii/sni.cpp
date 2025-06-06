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
#include <cmath>

bool isStrobogrammatic(std::string candidate)
{
    if ( candidate.length() == 0 )
        return false;

    if( candidate.find_first_of('2') != std::string::npos )
        return false;
    if( candidate.find_first_of('3') != std::string::npos )
        return false;
    if( candidate.find_first_of('4') != std::string::npos )
        return false;
    if( candidate.find_first_of('5') != std::string::npos )
        return false;
    if( candidate.find_first_of('7') != std::string::npos )
        return false;
    
    int low = 0;
    int high = candidate.length()-1;
    while( low <= high )
    {
        char lchar = candidate[low];
        char hchar = candidate[high];

        if( ( lchar == '0' ) && ( hchar == '0' ))
        {
        }
        else if( ( lchar == '8' ) && ( hchar == '8' ))
        {
        }
        else if( ( lchar == '1' ) && ( hchar == '1' ))
        {
        }
        else if( ( lchar == '6' ) && ( hchar == '9' ))
        {
        }
        else if( ( lchar == '9' ) && ( hchar == '6' ))
        {
        }
        else
            return false;

        low++;
        high--;
    }
    return true;
}



std::vector<std::string> findStrobogrammatic(int n)
{
    std::vector<std::string> retval;
    int start = pow(10,n-1);
    if( n == 1 )
        start = 0;
    int end   = pow(10,( n ));
    for(int index=start;index<end;index++)
    {
        std::string candidate = std::to_string(index);
        if( isStrobogrammatic( candidate ) )
        {
            retval.push_back( candidate );
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0247-trobogrammatic-number-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 2;
        std::vector<std::string> expected = {"11","69","88","96"};
        std::vector<std::string> result   = findStrobogrammatic(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 1;
        std::vector<std::string> expected = {"0","1","8"};
        std::vector<std::string> result   = findStrobogrammatic(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
