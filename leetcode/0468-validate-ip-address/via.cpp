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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>
#include <string.h>




bool isValidIP6Chunk(std::string &chunk)
{
    if ( chunk.length() > 4 )
        return false;
    int num_zeroes = 0;
    for(const auto curr : chunk )
    {
        if( ! std::isxdigit ( curr ) )
            return false;
        if( curr == '0' )
            num_zeroes++;
    }
    return true;
}

bool isValidIP4Chunk(std::string &chunk)
{
    if ( chunk.length() > 3 )
        return false;

    for(const auto curr : chunk )
    {
        if( ! isdigit ( curr ) )
            return false;
    }
    int ival = atoi(chunk.c_str());
    if(( ival < 0 ) || (ival > 255 ))
        return false;

    if(( chunk[0] == '0' ) && ( chunk.length() > 1 ))
        return false;

    return true;
}

int countOfCharInString(const char needle, const std::string &haystack)
{
    int count = 0;
    for(const auto curr : haystack )
        if( curr == needle )
            count++;
    return count;
}
    
std::string validIPAddress(std::string queryIP)
{
    if( queryIP.length() > 39 )
        return "Neither";

    char buf[256];
    snprintf(buf,256,"%s",queryIP.c_str());
    if( queryIP.find(".") != std::string::npos )
    {
        int dotcount = countOfCharInString('.',queryIP );
        char *CH = strtok((char *)&buf[0],".");
        std::vector<std::string> blocks;
        while(CH)
        {
            std::string current(CH);
            for(auto cchar : current )
            {
                if( ! isdigit(cchar))
                    continue;
            }
            blocks.push_back(current);
            CH = strtok(NULL,".");
        }
        int valid_block = 0;
        for(auto cblock : blocks )
        {
            if( isValidIP4Chunk(cblock) )
                valid_block++;
        }
        if(( blocks.size() == 4 ) && ( valid_block == 4 ) && ( dotcount == 3 ))
            return "IPv4";
    }
    else if( queryIP.find(":") != std::string::npos )
    {
        int colonCount = countOfCharInString(':',queryIP );
        char *CH = strtok((char *)&buf[0],":");
        std::vector<std::string> blocks;
        while(CH)
        {
            std::string current(CH);
            for(auto cchar : current )
            {
                if( ! isdigit(cchar))
                    continue;
            }
            blocks.push_back(current);
            CH = strtok(NULL,":");
        }
        int valid_block = 0;
        for(auto cblock : blocks )
        {
            if( isValidIP6Chunk(cblock))
                valid_block++;
        }
        if(( blocks.size() == 8 ) && ( valid_block == 8 ) && (colonCount == 7 ))
            return "IPv6";
    }
    return "Neither";
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0468-validate-ip-address" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string queryIP = "172.16.254.1";
        std::string result = validIPAddress(queryIP);
        std::string expected = "IPv4";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
        std::string result = validIPAddress(queryIP);
        std::string expected = "IPv6";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string queryIP = "256.256.256.256";
        std::string result = validIPAddress(queryIP);
        std::string expected = "Neither";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
        std::string result = validIPAddress(queryIP);
        std::string expected = "Neither";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string queryIP = "1e1.4.5.6";
        std::string result = validIPAddress(queryIP);
        std::string expected = "Neither";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string queryIP = "2001:0db8:85a3:0000:0:8A2E:0370:733a";
        std::string result = validIPAddress(queryIP);
        std::string expected = "IPv6";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}

