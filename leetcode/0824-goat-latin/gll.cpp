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


std::unordered_set<char> vowels = { 'a','A','e','E','i','I','o','O','u','U' };

bool isVowel(const char candidate)
{
    if( vowels.count(candidate))
        return true;
    return false;
}

std::string toGoatLatin(std::string sentence)
{
    std::string retval = "";
    char *clone = strdup( sentence.c_str());
    char *ch = strtok( clone, " " );
    int count = 1;
    bool first = true;
    while( ch != NULL )
    {
        if( ! first )
            retval.append(" ");
        first = false;
        std::string word(ch);
        if( isVowel(ch[0]))
        {
            retval.append(word);
        }
        else
        {
            retval.append(word.substr(1));
            retval.push_back(ch[0]);
        }
        retval.append("ma");
        int aaas = count;
        while( aaas > 0 )
        {
            retval.append("a");
            aaas--;
        }
        ch = strtok(NULL," ");
        count++;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0824-goat-latin" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string sentence = "I speak Goat Latin";
        std::string expected = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
        std::string result = toGoatLatin(sentence);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string sentence = "The quick brown fox jumped over the lazy dog";
        std::string expected = "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
        std::string result = toGoatLatin(sentence);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
