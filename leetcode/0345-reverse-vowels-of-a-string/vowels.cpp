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
    std::string::iterator tail = output_string.end();
    char test;
    bool tail_found = false;
    bool head_found = false;
    bool should_exit = false;
    while( ! should_exit )
    {
        test = *head;
        while(( head != output_string.end()) && ( head < tail ))
        {
            if( isVowel( *head ))
            {
                head_found = true;
                break;
            }
            head++;
        }
        while( ( tail != output_string.begin() ) && ( tail > head ) )
        {
            if( isVowel( *tail ))
            {
                tail_found = true;
                break;
            }
            tail--;
        }
        if(( tail_found && head_found )
           && ( head != tail ))
        {
            tail_found = false;
            head_found = false;
            std::iter_swap( head, tail );
            head++;
            tail--;
        }
        if(( head == tail )
           || ( tail == output_string.begin() )
           || ( head == output_string.end()))
        {
            should_exit = true;
        }
    }
    return output_string;
}


int main(int argc, char **argv)
{
    printf("Leetcode #345 - Reverse Vowels of a String\n");
    {
        std::string input_string = "IceCreAm"; 
        std::cout << "Input : " << input_string << std::endl;
        std::string output_string = reverseVowels(input_string);
        std::cout << " Output : " << output_string << std::endl;
    }
    {
        std::string input_string = "leetcode";
        std::cout << "Input : " << input_string << std::endl;
        std::string output_string = reverseVowels(input_string);
        std::cout << "Output : " << output_string << std::endl;
    }
}
