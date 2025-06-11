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

int characterReplacement(std::string s, int k)
{
    std::vector<int> character_counts(26, 0);
    int left = 0;
    int most_freq_char = 0;
    int longest_possible = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        char current = s[right];
        int cindex = current - 'A';
        character_counts[cindex]++;

        // check to see if incrementing the count of this char has now made it the most frequent char
        // (we don't actually care what that character is)
        most_freq_char = std::max(most_freq_char, character_counts[cindex]); 


        // if the current window size, minus the count of the most
        // frequent character, is greater than k then it's invalid.
        // So slide up left until it is.
        while ((right - left + 1) - most_freq_char > k)
        {
            char lchar = s[left];
            int lindex = lchar - 'A';
            character_counts[lindex]--;
            left++;
        }
        longest_possible = std::max(longest_possible, right - left + 1);
    }
    return longest_possible;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0424-longest-repeating-character-replacement" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "ABAB";
        int k = 2;
        int expected = 4;
        int result = characterReplacement(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "AABABBA";
        int k = 1;
        int expected = 4;
        int result = characterReplacement(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
