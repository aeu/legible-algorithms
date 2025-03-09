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



bool areAdjacent(std::string &lhs,
                 std::string &rhs)
{
    int diffs = 0;
    for(int index=0;index<lhs.size();index++)
    {
        if( lhs[index] != rhs[index] )
            diffs++;
    }
    return ( diffs == 1 );
}

int ladderLength(std::string beginWord,
                 std::string endWord,
                 std::vector<std::string> &wordlist)
{
    struct LadderStep {
        int step_count;
        std::string word;
    };
    int ladder_length = INT_MAX; 
    std::queue<LadderStep> bfs_queue;
    std::unordered_set<std::string> words_set;
    for( auto current : wordlist )
    {
        words_set.insert( current );
    }
    
    bfs_queue.push( { 1, beginWord });
    words_set.erase( beginWord );
    while( ! bfs_queue.empty() )
    {
        LadderStep current = bfs_queue.front();
        bfs_queue.pop();
        
        if( current.word == endWord )
        {
            ladder_length = std::min( ladder_length, current.step_count );
            continue;
        }
        std::string temp = current.word;
        for (int i = 0; i < temp.size(); i++)
        {
            char original = temp[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == original)
                    continue;
                temp[i] = c;

                if (words_set.find(temp) != words_set.end())
                {
                    bfs_queue.push({current.step_count + 1, temp});
                    words_set.erase(temp);
                }
            }
            temp[i] = original;
        }
    }
    if( ladder_length == INT_MAX )
        return 0;
    return ladder_length;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::string beginWord = "hit";
        std::string endWord = "cog";
        std::vector<std::string> wordlist =
            {
                "hot", "dot", "dog", "lot", "log", "cog"
            };
        int expected = 5;
        int result   = ladderLength(beginWord, endWord, wordlist);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string beginWord = "hit";
        std::string endWord = "cog";
        std::vector<std::string> wordlist =
            { "hot", "dot", "dog", "lot", "log" };
        int expected = 0;
        int result   = ladderLength(beginWord, endWord, wordlist);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
