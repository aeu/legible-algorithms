// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


class RecentCounter {
private:
protected:
    std::vector<int> pings;
public:
    RecentCounter() {
        
    }
    
    int ping(int t)
    {
        pings.push_back(t);
        auto it = pings.begin();
        while( it != pings.end() )
        {
            if( *it < ( t - 3000 ) )
            {
                it = pings.erase(it);
            }
            else
            {
                break;
            }
        }
        return pings.size();
    }
};


int main(int argc, char **argv)
{
    int test_case = 1;
    RecentCounter fred;
    fred.ping( 500);
    fred.ping(800);
    fred.ping( 900 );
#if 0    
    {
        std::string word1 = "abc";
        std::string word2 = "bca";
        bool expected = true;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "a";
        std::string word2 = "aa";
        bool expected = false;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "cabbba";
        std::string word2 = "abbccc";
        bool expected = true;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
#endif
    return test_case;
}
