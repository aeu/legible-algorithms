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

struct FreqInfo
{
    char letter;
    int count;
};

    
struct FreqInfoSorter {
    bool operator()(FreqInfo &lhs,FreqInfo &rhs)
    {
        return lhs.count < rhs.count;
    }
};
    
std::string frequencySort(std::string s)
{
    std::map<char,int> freq;
    for(auto const curr: s )
    {
        freq[curr]++;
    }
    
    std::priority_queue<FreqInfo,std::vector<FreqInfo>,FreqInfoSorter> fqueue;
    for(const auto &[letter,count] : freq )
    {
        fqueue.push({letter,count});
    }
    std::string retval;
    while( ! fqueue.empty() )
    {
        FreqInfo curr = fqueue.top();
        fqueue.pop();
        for(int index=0;index<curr.count;index++)
            retval.push_back( curr.letter );
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0451-sort-characters-by-frequeny" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "tree";
        std::string expected = "eert";
        std::string result = frequencySort(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "cccaaa";
        std::string expected = "aaaccc";
        std::string result = frequencySort(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "Aabb";
        std::string expected = "bbAa";
        std::string result = frequencySort(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
