// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <stdlib.h>

std::string addStrings(std::string num1,std::string num2)
{
    std::cout << "add strings " << num1 << " " << num2 << std::endl;
    
    std::string retval;
    std::reverse(num1.begin(),num1.end());
    std::reverse(num2.begin(),num2.end());
    std::cout << num1 << " " << num2 << std::endl;

    char c1 = '0';
    char c2 = '0';
    int carry = 0; 
    int index = 0;
    bool done = false;
    
    while( ! done )
    {
        c1 = '0';
        c2 = '0';

        if( index < num1.length() )
            c1 = num1[index];
        
        if( index < num2.length() )
            c2 = num2[index];

        int i1 = c1 - '0';
        int i2 = c2 - '0';

        int sum = i1 + i2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        if(( digit != 0 ) || ( carry != 0 ))
            retval += std::to_string(digit);
        
        // std::cout << i1 << " + " << i2 << " = " << digit << " with carry of " << carry << std::endl;
        
        if( index > num1.length() && ( index > num2.length()) && ( carry == 0 ))
            done = true;
        index++;
    }
    std::reverse(retval.begin(),retval.end());
    if( retval.length() == 0 )
        retval = "0";
    // std::cout << "RV: " << retval << std::endl;
    return retval;
}
    

int main(int argc, char **argv)
{
    std::cout << std::endl << "0415-add-strings" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string num1 = "1";
        std::string num2 = "9";
        std::string result = addStrings(num1,num2);
        std::string expected = "10";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string num1 = "11";
        std::string num2 = "123";
        std::string result = addStrings(num1,num2);
        std::string expected = "134";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string num1 = "456";
        std::string num2 = "77";
        std::string result = addStrings(num1,num2);
        std::string expected = "533";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string num1 = "0";
        std::string num2 = "0";
        std::string result = addStrings(num1,num2);
        std::string expected = "0";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
