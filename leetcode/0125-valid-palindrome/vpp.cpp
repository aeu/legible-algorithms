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
#include <stack>
#include <ctype.h>


char validateChar(const std::string input, int index)
{
    if(( index >= 0 ) && ( index < input.length() ))
    {
        char candidate = input[index];
        if( isdigit( candidate ) )
            return candidate;
        
        char lower = tolower(candidate);
        if(( lower >= 97 ) && ( lower <= 122 )) 
        {
            return lower;
        }
    }
    return -1;
}

bool isPalindrome(std::string input)
{
    if( input.length() == 0 )
        return true;
    
    bool is_palindrome = true;
    int left = 0;
    int right = input.length() -1 ;
    char left_char;
    char right_char;
    int comparisons_made = 0;
    while( left < right )
    {
        left_char = validateChar(input,left);
        while(( left_char == -1 ) && ( left < right ))
        {
            left++;
            left_char = validateChar(input,left);
        }
        right_char = validateChar(input,right);
        while(( right_char == -1 ) && ( right > left ))
        {
            right--;
            right_char = validateChar(input,right);
        }
        // std::cout << "about to compare " << left_char << " and " << right_char << std::endl;
        // std::cout << "left " << left << " and " << right << std::endl;
        if( left == right )
        {
            // if( comparisons_made == 0 )
            // {
            //     is_palindrome = false;
            //     break;
            // }
            break;
        }
        if(( left_char == right_char ) && ( left_char != -1 ))
        {
            left++;
            right--;
            comparisons_made++;
        }
        else
        {
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #125 - Valid Palindrome" << std::endl << std::endl;
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::string input = "0P";
        std::cout << "Checking : " << input << std::endl;
        bool is_palindrome = isPalindrome(input);
        std::cout << "Is palindrome : " << is_palindrome << std::endl;
    }
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::string input = "a.";
        std::cout << "Checking : " << input << std::endl;
        bool is_palindrome = isPalindrome(input);
        std::cout << "Is palindrome : " << is_palindrome << std::endl;
    }
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::string input = "A man, a plan, a canal: Panama";
        std::cout << "Checking : " << input << std::endl;
        bool is_palindrome = isPalindrome(input);
        std::cout << "Is palindrome : " << is_palindrome << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::string input = "race a car";
        std::cout << "Checking : " << input << std::endl;
        bool is_palindrome = isPalindrome(input);
        std::cout << "Is palindrome : " << is_palindrome << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::string input = "";
        std::cout << "Checking : " << input << std::endl;
        bool is_palindrome = isPalindrome(input);
        std::cout << "Is palindrome : " << is_palindrome << std::endl;
    }
    return -1;
}
