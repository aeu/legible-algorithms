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


std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> values;
    char buf[256];
    for(auto curr = 1;curr<=n;curr++)
    {
        bool div3 = (( curr % 3 ) == 0 );
        bool div5 = (( curr % 5 ) == 0 );

        if( div3 && div5 )
        {
            values.push_back("FizzBuzz");
        }
        else if( div3 )
            values.push_back("Fizz");
        else if( div5 )
            values.push_back("Buzz");
        else {
            snprintf(buf,255,"%d",curr);
            values.push_back(std::string(buf));
        }
    }
    return values;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0412-fizz-buzz" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 3;
        std::vector<std::string> expected = {"1","2","Fizz"};
        std::vector<std::string> result = fizzBuzz(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 5;
        std::vector<std::string> expected = {"1","2","Fizz","4","Buzz"};;
        std::vector<std::string> result = fizzBuzz(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 15;
        std::vector<std::string> expected = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
        std::vector<std::string> result = fizzBuzz(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
