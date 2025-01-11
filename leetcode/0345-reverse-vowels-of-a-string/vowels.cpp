// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

bool isVowel(const char candidate)
{
    switch( candidate )
    {
    case 'a' :
    case 'e' :
    case 'i' :
    case 'o' :
    case 'u' :
    case 'A' :
    case 'E' :
    case 'I' :
    case 'O' :
    case 'U' :
        return true;
    default:
        return false;
    }
}

std::string reverseVowels(std::string input_string)
{
    std::string output_string = input_string;
    std::string::iterator head = output_string.begin();
    std::string::iterator tail = output_string.end() - 1;
    while( head < tail )
    {
        while(( ! isVowel(*head)) && (head < tail))
        {
            head++;
        }
        while( !isVowel(*tail) && ( tail > head ))
        {
            tail--;
        }
        if( head < tail )
        {
            std::iter_swap( head, tail );
            head++;
            tail--;
        }
    }
    return output_string;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #345 - Reverse Vowels of a String" << std::endl;
    {
        std::string input_string = "IceCreAm"; 
        std::cout << "Input : " << input_string << std::endl;
        std::string output_string = reverseVowels(input_string);
        std::cout << "Output : " << output_string << std::endl;
    }
    {
        std::string input_string = "leetcode";
        std::cout << "Input : " << input_string << std::endl;
        std::string output_string = reverseVowels(input_string);
        std::cout << "Output : " << output_string << std::endl;
    }
}
