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


bool isDecimal(std::string s)
{
    int digits = 0;
    int periods = 0;
    for(int index=0;index<s.length();index++)
    {
        char curr = s[index];
        if(( curr == '+' ) || ( curr == '-' ))
        {
            if( index != 0 )
            {
                return false;
            }
        }
        else if( curr == '.' )
        {
            periods++;
            if( periods > 1 )
                return false;
        }
        else if( ! isdigit( curr ) )
        {
            return false;
        }
        else
        {
            digits++;
        }
        
    }
    if( digits == 0 )
        return false;
    return true;
}



bool isInteger(std::string s)
{
    int digits = 0;
    for(int index=0;index<s.length();index++)
    {
        char curr = s[index];
        if(( curr == '+' ) || ( curr == '-' ))
        {
            if( index != 0 )
            {
                return false;
            }
        }
        else if( ! isdigit(curr))
        {
            return false;
        }
        else
        {
            digits++;
        }
    }
    if( digits == 0 )
        return false;
    return true;
}

bool isExponentValid(std::string s)
{
    int digits = 0;
    for(int index=0;index<s.length();index++)
    {
        char curr = s[index];
        if(( curr == '+' ) || ( curr == '-' ))
        {
            if( index != 0 )
            {
                return false;
            }
        }
        else if ( ! isdigit( curr ))
        {
            return false;
        }
        else
        {
            digits++;
        }
    }
    if( digits == 0 )
        return false;
    return true;
}


bool isNumber(std::string s)
{
    if( s.length() == 0 )
        return false;

    auto epos = s.find('e');
    std::string number;
    std::string exponent;
    
    if( epos != std::string::npos )
    {
        number = s.substr(0,epos);
        exponent = s.substr(epos+1);
    }
    epos = s.find('E');
    if( epos != std::string::npos )
    {
        number = s.substr(0,epos);
        exponent = s.substr(epos+1);
    }
    bool is_integer = false;
    bool is_decimal = false;
    if( exponent.length() > 0 )
    {
        bool exponent_valid = isExponentValid(exponent);
        if( exponent_valid == false )
            return false;
        is_integer = isInteger(number);
        is_decimal = isDecimal(number);
    }
    else
    {
        is_integer = isInteger(s);
        is_decimal = isDecimal(s);
    }
    
    if(( is_integer == false ) && ( is_decimal == false ))
        return false;
    
    return true;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0065-valid-number" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "-123.456e7.8e9";
        bool expected = false;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-123.456e7.89";
        bool expected = false;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-123.456e7.8.9";
        bool expected = false;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-123.456e7.89";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "2";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "0089";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-0.1";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "+3.14";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "4.";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-.9";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "2e10";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-90E3";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "3e+7";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "+6e-1";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "53.5e93";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "-123.456e789";
        bool expected = true;
        bool result = isNumber(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}




