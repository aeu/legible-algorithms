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

std::string processSegment(std::string candidate,
                           int start_point)
{
    //    std::cout << "Process segment called, with start point : " << start_point << " : " << candidate.substr(start_point) << std::endl;
    std::string retval;
    char current;
    for(int index=start_point;index<candidate.length();index++)
    {
        current = candidate[index];
        //  std::cout << "current: " << current << std::endl;
        if( ( current != '[' ) && ( current != ']' ))
        {
            retval += current;
        }
        else if( current == '[' )
        {
            char last_char;
            bool done = false;
            std::string multiplier = "";
            std::string subsegment = processSegment(candidate, index+1);
            while( ! retval.empty() && ! done )
            {
                last_char = retval.back();
                if( isdigit( last_char ))
                {
                    retval.pop_back();
                    std::string last_str(1,last_char);
                    multiplier.insert(0,last_str);
                    // std::string(last_char));
                }
                else
                {
                    done = true;
                }
            }
            if( ! multiplier.empty() )
            {
                int multiplier_as_int = atoi( multiplier.c_str());
                //                std::cout << "multiplier : " << multiplier << " as int: " << multiplier_as_int << std::endl;
                while( multiplier_as_int > 0 )
                {
                    retval += subsegment;
                    multiplier_as_int--;
                }
            }
            index += subsegment.length()+1;
        }
        else if( current == ']' )
            break;
    }
    //    std::cout << "Returning: " << retval << std::endl;
    return retval;
}


std::string decodeString(std::string candidate)
{
    std::string retval;
    retval += processSegment(candidate,0);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0394 - Decode String" << std::endl;
    {
        std::string candidate  = "3[a]2[bc]";
        std::cout << "Candidate: " << candidate << std::endl;
        std::string decoded = decodeString( candidate );
        std::cout << "Decoded: " << decoded << std::endl;
    }
    {
        std::string candidate  = "3[a2[c]]";
        std::cout << "Candidate: " << candidate << std::endl;
        std::string decoded = decodeString( candidate );
        std::cout << "Decoded: " << decoded << std::endl;
    }
    {
        std::string candidate  = "2[abc]3[cd]ef";
        std::cout << "Candidate: " << candidate << std::endl;
        std::string decoded = decodeString( candidate );
        std::cout << "Decoded: " << decoded << std::endl;
    }
}
