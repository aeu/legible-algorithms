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


std::string addBinary(std::string a, std::string b)
{
    std::reverse(a.begin(),a.end());
    std::reverse(b.begin(),b.end());
    auto ait = a.begin();
    auto bit = b.begin();
    char ac;
    char bc;
    int carry = 0;
    std::string retval;
    while(( ait != a.end() ) && ( bit != b.end()))
    {
        ac = *ait;
        bc = *bit;
        int sum = ( ac - '0' ) + ( bc - '0' ) + carry;
        // std::cout << "a: " << ac << " b: " << bc << std::endl;
        // std::cout << "sum: " << sum << std::endl;
        if( sum == 0 )
        {
            retval.push_back('0');
        }
        else if ( sum == 1 )
        {
            retval.push_back('1');
            carry = 0;
        }
        else if ( sum == 2 )
        {
            retval.push_back('0');
            carry = 1;
        }
        else
        {
            retval.push_back('1');
            carry = 1;
        }
        ait++; bit++;
    }

    while( ait != a.end() )
    {
        ac = *ait;
        int sum = ( ac - '0' ) + carry;
        if( sum == 0 )
        {
            retval.push_back('0');
        }
        else if ( sum == 1 )
        {
            retval.push_back('1');
            carry = 0;
        }
        else if ( sum == 2 )
        {
            retval.push_back('0');
            carry = 1;
        }
        else
        {
            retval.push_back('1');
            carry = 1;
        }
        ait++;
    }
    while( bit != b.end() )
    {
        bc = *bit;
        int sum = ( bc - '0' ) + carry;
        if( sum == 0 )
        {
            retval.push_back('0');
        }
        else if ( sum == 1 )
        {
            retval.push_back('1');
            carry = 0;
        }
        else if ( sum == 2 )
        {
            retval.push_back('0');
            carry = 1;
        }
        else
        {
            retval.push_back('1');
            carry = 1;
        }
        bit++;
    }
    if( carry == 1 )
        retval.push_back('1');
    
    std::reverse(retval.begin(),retval.end());
    return retval;
}
int main(int argc, char **argv)
{
    std::cout << std::endl << "0067-add-binary" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string a = "11";
        std::string b = "1";
        std::string expected = "100";
        std::string result = addBinary(a,b);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string a = "1010";
        std::string b = "1011";
        std::string expected = "10101";
        std::string result = addBinary(a,b);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
