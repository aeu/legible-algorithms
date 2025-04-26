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
#include <limits.h>

int compress(std::vector<char>& chars)
{
    int tail = 0;
    int head = 0;
    int write = 0;
    while(head<chars.size())
    {
        if( chars[head] != chars[tail] )
        {
            int count = head - tail;
            chars[write++] = chars[tail];
            if( count > 1 )
            {
                std::string scount = std::to_string( count );
                for(auto curr : scount )
                {
                    chars[write++] = curr;
                }
            }
            tail = head;
        }
        head++;
    }
    if( head != tail )
    {
        int count = head - tail;
        chars[write++] = chars[tail];
        if( count > 1 )
        {
            std::string scount = std::to_string( count );
            for(auto curr : scount )
            {
                chars[write++] = curr;
            }
        }
    }
    return write;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<char> chars = {'a','a','b','b','c','c','c'};
        int expected = 6;
        int result = compress(chars);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<char> chars = {'a'};
        int expected = 1;
        int result = compress(chars);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
        int expected = 4;
        int result = compress(chars);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
