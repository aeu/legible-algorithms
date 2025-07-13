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


bool checkInclusion(std::string s1, std::string s2)
{
    std::vector<int> s1_dist(26,0);
    std::vector<int> s2_dist(26,0);
    
    for(const char curr : s1 )
    {
        int index = curr - 'a';
        s1_dist[index]++;
    }
    int s1len = s1.length();
    int head = 0;
    int tail = 0;
    while( head < s2.length() )
    {
        char curr = s2[head];
        int index = curr - 'a';
        s2_dist[index]++;
        if(( head - tail + 1) > s1len )
        {
            char tchar = s2[tail];
            int index = tchar - 'a';
            s2_dist[index]--;
            tail++;
        }
        if( s1_dist == s2_dist )
            return true;
        head++;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0567-permutation-in-string" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s1 = "ab";
        std::string s2 = "eidbaooo";
        bool expected = true;
        bool result = checkInclusion(s1,s2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::string s1 = "ab";
        std::string s2 = "eidboaoo";
        bool expected = false;
        bool result = checkInclusion(s1,s2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
