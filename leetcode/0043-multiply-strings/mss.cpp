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


 
void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


   //   C5C4C3C2C1
   //        1 2 3
   //        4 5 6
   //        61218
   //     051015..
   //   040812.... 

   //        56088
  // 2346
  //  574
  // 3804  


std::string multiply(std::string num1, std::string num2)
{
    if((num1 == "0") || ( num2 == "0" ))
        return "0";

    std::vector<int> columns((num1.length() + num2.length() + 1 ), 0 );
    std::reverse( num2.begin(), num2.end() );
    std::reverse( num1.begin(), num1.end() );
    std::string retval;
    int prod = 0;

    for(int n1index = 0; n1index < num1.length(); n1index++)
    {
        for(int n2index = 0; n2index < num2.length(); n2index++)
        {
            char n1c = num1[n1index];
            char n2c = num2[n2index];
            prod = ( n1c - '0' ) * ( n2c - '0' );
            //   int digit = prod % 10;
            //            int carry = prod / 10;
            std::cout << "adding : " << prod << " to column " << n1index + n2index << std::endl;
            columns[ n1index + n2index ] += prod;
        }
    }
    for(int index=0;index<columns.size()-1;index++)
    {
        int val = columns[index];
        int digit = val % 10;
        int carry = val / 10;
        char cdigit = digit + '0';
        retval.push_back( cdigit );
        columns[index+1] += carry;
    }
    std::reverse( retval.begin(),retval.end() );
    std::string final;
    bool found_digit = false;
    for( auto curr : retval )
    {
        if(( curr == '0' ) && ( found_digit == false ))
            continue;
        else
        {
            found_digit = true;
            final.push_back( curr );
        }
    }
    return final;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0043-multiply-strings" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string num1 = "123";
        std::string num2 = "456";
        std::string result = multiply(num1,num2);
        std::string expected = "56088";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string num1 = "2";
        std::string num2 = "3";
        std::string result = multiply(num1,num2);
        std::string expected = "6";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
