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
#include <sstream>

std::string reverseWords(std::string &input)
{
    std::string retval;
    bool first_word = true;
    std::ostringstream output;
    std::string::iterator word_start = input.end() - 1;
    std::string::iterator word_end   = input.end();
    while( word_start >= input.begin() )
    {
        while( ( *word_start != ' ' ) && ( word_start >= input.begin()))
        {
            word_start--;
        }
        if(( *word_start == ' ' ) || ( word_start == input.begin()))
        {
            std::string found = std::string( (word_start+1), word_end );
            if( found.length() )
            {
                if( ! first_word )
                {
                    output << " ";
                }
                output << found;
                first_word = false;
            }
            word_end = word_start;
            word_start--;
        }
    }
    std::string found = std::string( (word_start+1), word_end );
    if( found.length() )
    {
        if( ! first_word )
        {
            output << " ";
        }
        output << found;
    }
    return output.str();
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #151 - Reverse Words in a String" << std::endl << std::endl;
    {
        std::string input_string = "the sky is blue"; 
        std::cout << "Input[" << input_string << "]" << std::endl;
        std::string output_string = reverseWords(input_string);
        std::cout << "Output[" << output_string << "]" << std::endl;
    }
    {
        std::string input_string = "    hello world  ";
        std::cout << "Input[" << input_string << "]" << std::endl;
        std::string output_string = reverseWords(input_string);
        std::cout << "Output[" << output_string << "]" << std::endl;
        std::cout << "Output[" << output_string << "]" << std::endl;
    }
    {
        std::string input_string = "a good    example";
        std::cout << "Input[" << input_string << "]" << std::endl;
        std::string output_string = reverseWords(input_string);
        std::cout << "Output[" << output_string << "]" << std::endl;
    }
}
