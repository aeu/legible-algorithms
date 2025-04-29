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


bool isValidIp(const std::string candidate)
{
    if( candidate.length() <= 0 )
        return false;
    if( candidate.length() > 3 )
        return false;
    if( ( candidate[0] == '0') && candidate.length() > 1 )
        return false;
    long ip = std::stol( candidate );
    if( ( ip < 0 ) || ( ip > 255 ))
        return false;
    if( ( ip > 0 ) && ( candidate[0] == '0' ))
        return false;
    return true;
}


void backtrace(int start_index,
               std::string s,
               std::vector<std::string> &path,
               std::vector<std::string> &retval)
{
    // all characters have been used
    if( start_index == s.length() )
    {
        // is comprised of 4 strings, so a valid IP
        if( path.size() == 4 )
        {
            std::string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            retval.push_back(ip);
        }
    }

    for(int index=start_index;index<s.length();index++)
    {
        std::string curr = s.substr(start_index,index-start_index+1);

        if(isValidIp(curr ))
        {
            path.push_back(curr);
            backtrace(index+1,s,path,retval);
            path.pop_back();
        }
    }
}


std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::vector<std::string> retval;
    std::vector<std::string> path;
    backtrace(0,s,path,retval);
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
