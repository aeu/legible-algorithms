// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

std::string reverseWords(std::string &input)
{
    std::string retval = "";
    char *copy = strdup(input.c_str());

    char *tmp = strtok(copy, " ");
    while( tmp )
    {
        std::string newstr(tmp);
        // don't do this the first time so we don't get a trailing
        // space
        if( retval.length() > 0 )
            newstr.append(" ");
        retval.insert(0,newstr);
        tmp = strtok(NULL, " ");
    }
    free(copy);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #151 - Reverse Words in a String" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string input_string = "the sky is blue"; 
        std::string expected = "blue is sky the";
        std::string result = reverseWords(input_string);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string input_string = "    hello world  ";
        std::string expected = "world hello";
        std::string result = reverseWords(input_string);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string input_string = "a good    example";
        std::string expected = "example good a";
        std::string result = reverseWords(input_string);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
