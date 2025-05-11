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

struct DupInfo
{
    char c;
    int sequence;
};


std::string removeDuplicates(std::string s, int k)
{
    std::stack<DupInfo> cstack;
    int index=0;
    while( index < s.length() )
    {
        char curr = s[index];
        if( cstack.empty() )
            cstack.push({curr,1});
        else
        {
            DupInfo di = cstack.top();
            if( di.c == curr )
            {
                int newc = di.sequence+1;
                cstack.push({curr,newc});
                if( newc == k )
                {
                    while(( newc > 0 ) && ( ! cstack.empty()))
                    {
                        cstack.pop();
                        newc--;
                    }
                }
            }
            else
            {
                cstack.push({curr,1});
            }
        }
        index++;
    }
    std::string retval;
    while( ! cstack.empty() )
    {
        DupInfo di = cstack.top();
        retval.push_back(di.c);
        cstack.pop();
    }
    std::reverse(retval.begin(),retval.end());
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1209-remove-all-adjacent-duplicates-in-string-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "abcd";
        int k = 2;
        std::string expected = "abcd";
        std::string result   = removeDuplicates(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "deeedbbcccbdaa";
        int k = 3;
        std::string expected = "aa";
        std::string result   = removeDuplicates(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "pbbcggttciiippooaais";
        int k = 2;
        std::string expected = "ps";
        std::string result   = removeDuplicates(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
