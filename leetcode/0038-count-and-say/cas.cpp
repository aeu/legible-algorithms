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


std::string countAndSay(int n)
{
    if( n == 1 )
        return "1";
    if( n == 2 )
        return "11";

    std::string previous = "11";
    std::string current = "";
    int count=1;
    char pchar = previous[0];
    while( n > 2 )
    {
        for(int index=1;index<previous.length();index++)
        {
            if( previous[index] == pchar )
            {
                count++;
                continue;
            }
            else
            {
                current += std::to_string(count);
                current += pchar;
                count = 1;
                pchar = previous[index];
            }
        }
        current += std::to_string(count);
        current += pchar;
        count = 0;
        n--;
        if( n > 2 )
        {
            previous = current;
            current = "";
            count = 1;
            pchar = previous[0];
        }
    }
    return current;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0038-count-and-say" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 1;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        std::cout << n << ": " << countAndSay(n) << std::endl; n++;
        // std::vector<int> nums  = {1,2,3};
        // int expected = 0;
        // int result = 0;
        // std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
