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


std::vector<std::pair<char,char>> pairs {
    { '6' , '9' },
    { '9' , '6' },
    { '8' , '8' },
    { '1' , '1' },
    { '0' , '0' },
};


void backtrace(std::string number,
               int n,
               std::vector<std::string> &results)
{
    if( number.length() > n )
        return;

    if(( n == 1 ) && ( number.length() == 1 ))
    {
        results.push_back( number );
        return;
    }
        
    if(( number.length() == n ) && ( number[0] != '0' ))
    {
        std::cout << number << std::endl;
        results.push_back( number );
        return;
    }

    for( const auto curr : pairs )
    {
        char first  = curr.first;
        char second = curr.second;
        std::string lnumber;
        lnumber += first;
        lnumber.append(number);
        lnumber += second;
        backtrace( lnumber,n,results);
    }
}


std::vector<std::string> findStrobogrammatic(int n)
{
    std::vector<std::string> results;
    if( n % 2 )
    {
        backtrace( "0", n, results );
        backtrace( "1", n, results );
        backtrace( "8", n, results );
    }
    else
    {
        backtrace("",n,results);
    }
    return results;
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
