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
#include <cstdlib>
#include <limits.h>


bool isValidIp(std::string candidate)
{
    if( candidate.length() <= 0 )
        return false;
    if( candidate.length() > 3 )
        return false;
    
    long value = std::stol(candidate);
    if( ( value == 0 ) && ( candidate.length() > 1 ))
        return false;
    if(( value > 0 ) && ( candidate[0] == '0' ))
        return false;
    if((value < 0 ) || ( value > 255 ))
        return false;
    return true;
}

void backtrace(std::string s,
               int start_index,
               std::vector<std::string> &path,
               std::vector<std::string> &retval)
{
    if( start_index == s.length() )
    {
        if( path.size() == 4 )
        {
            std::string ip_address = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            retval.push_back( ip_address );
        }
    }
    for(int index=start_index;index<s.length();index++)
    {
        std::string candidate = s.substr(start_index,index-start_index+1);
        if( isValidIp( candidate ) )
        {
            path.push_back( candidate );
            backtrace(s,index+1,path,retval);
            path.pop_back();
        }
    }
}


std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::vector<std::string> path;
    std::vector<std::string> retval;
    backtrace(s,0,path,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC0093 - Restore IP Addresses" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "25525511135";
        std::vector<std::string> expected = {"255.255.11.135","255.255.111.35"};
        std::vector<std::string> result   = restoreIpAddresses(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //   std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
