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

std::vector<int> plusOne(std::vector<int>& digits)
{
    if( digits.size() == 0 )
        return digits;
    
    std::vector<int> retval = digits;
    int carry = 1;
    for(int index=retval.size()-1;index>=0;index--)
    {
        retval[index] += carry;
        if( retval[index] == 10 )
        {
            carry = 1;
            retval[index] = 0;
        }
        else
        {
            carry = 0;
            break;
        }
    }
    if( carry == 1 )
        retval.insert(retval.begin(),1);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0066-plus-one" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> digits  = {1,2,3};
        std::vector<int> expected = {1,2,4};
        std::vector<int> result = plusOne(digits);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> digits  = {4,3,2,1};
        std::vector<int> expected = {4,3,2,2};
        std::vector<int> result = plusOne(digits);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> digits  = {9};
        std::vector<int> expected = {1,0};
        std::vector<int> result = plusOne(digits);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> digits  = {9,9,9};
        std::vector<int> expected = {1,0,0,0};
        std::vector<int> result = plusOne(digits);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
