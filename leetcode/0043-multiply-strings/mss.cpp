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
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


std::string multiply(std::string num1, std::string num2)
{
    if((num1 == "0") || ( num2 == "0" ))
        return "0";

    std::reverse(num1.begin(),num1.end());
    std::reverse(num2.begin(),num2.end());
    
    int carry  = 0;
    int n1digit = 0;
    int n2digit = 0;
    int total  = 0;
    int index = 0;
    std::string retval;
    
    while( ( index < num1.length() ) && ( index < num2.length() ))
    {
        n1digit = num1[index] - '0';
        n2digit = num2[index] - '0';
        int prod = ( n1digit * n2digit ) + carry ;
        int digit = prod % 10;
        int carry = ( prod - digit ) / 10;

        std::cout << "n1digit " << n1digit << std::endl;
        std::cout << "n2digit " << n2digit << std::endl;
        std::cout << "prod    " << prod    << std::endl;
        std::cout << "digit   " << digit   << std::endl;
        std::cout << "carry   " << carry   << std::endl;
        retval+= std::to_string( prod );
        index++;
    }
    
    while( index < num1.length() )
    {
        n1digit = num1[index] - '0';
        int prod = prod + carry;
        carry = 0;
        retval += std::to_string( prod );
        index++;
    }
    while( index < num2.length() )
    {
        n2digit = num2[index] - '0';
        int prod = prod + carry;
        carry = 0;
        retval += std::to_string( prod );
        index++;
    }
    std::cout << "reval: " << retval;
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0043-multiply-strings" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string num1 = "2";
        std::string num2 = "3";
        std::string result = multiply(num1,num2);
        std::string expected = "6";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string num1 = "123";
        std::string num2 = "456";
        std::string result = multiply(num1,num2);
        std::string expected = "56088";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
