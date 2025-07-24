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
#include <cstring>

int lengthOfLastWord(std::string s)
{
    char *temp = strdup(s.c_str());
    char *curr = strtok(temp," ");
    char *last ;
    while( curr != NULL )
    {
        last = curr;
        curr = strtok(NULL," ");
    }
    int retval = strlen(last);
    free(temp);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0058-length-of-last-word" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "Hello World";
        int expected = 5;
        int result = lengthOfLastWord(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "    fly me     to    the moon   ";
        int expected = 4;
        int result = lengthOfLastWord(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "luffy is still joyboy";
        int expected = 6;
        int result = lengthOfLastWord(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
