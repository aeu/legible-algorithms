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

bool dfs(int start_index,
         std::string s,
         std::vector<std::string> &wordDict,
         std::unordered_map<int,bool> &memo)
{
    bool retval = false;
    if( start_index == s.length() )
    {
        return true;
    }

    if (memo.find(start_index) != memo.end())
        return memo[start_index];
    
    for(auto curr : wordDict )
    {
        if (s.substr(start_index, curr.length()) == curr)
        {
            int chars_left = s.length() - curr.length();
            if( chars_left == 0 )
            {
                memo[start_index] = true;
                return true;
            }
            else
            {
                bool result = dfs(start_index+curr.length(),s,wordDict,memo);
                memo[start_index] = result;
                if( result == true )
                    return result;
            }
        }
    }
    return retval;
}

struct Longer {
    bool operator()(const std::string &lhs, const std::string &rhs)
    {
        return ( lhs.length() > rhs.length() );
    }
};

    

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    std::sort(wordDict.begin(),wordDict.end(),Longer());
    std::unordered_map<int,bool> memo;
    bool retval = dfs(0,s,wordDict,memo);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "139. Word Break" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "leetcode";
        std::vector<std::string> wordDict = {"leet","code"};
        int expected = true;
        int result = wordBreak(s,wordDict);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "applepenapple";
        std::vector<std::string> wordDict = {"apple","pen"};
        int expected = true;
        int result = wordBreak(s,wordDict);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "catsandog";
        std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
        int expected = false;
        int result = wordBreak(s,wordDict);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
