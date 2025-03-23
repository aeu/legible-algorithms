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
#include <stack>

std::string simplifyPath(std::string path)
{
    std::stack<std::string> spath;
    char *raw = strdup( path.c_str() );
    char *c = strtok(raw,"/");
    while(c)
    {
        std::string current(c);
        if( current == "" )
        {
        }
        else if( current == "." )
        {
        }
        else if( current == ".." )
        {
            if( ! spath.empty() )
                spath.pop();
        }
        else
        {
            spath.push(current);
        }
        c = strtok(NULL,"/");
    }
    free(raw);
    std::vector<std::string> full; 
    while( ! spath.empty() )
    {
        full.push_back( spath.top() );
        spath.pop();
    }
    std::string retval = "/";
    for(int index=full.size()-1;index>=0;index--)
    {
        retval += full[index];
        if( index > 0 )
            retval += "/";
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #71 - Simplify Path" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string path = "/home/";
        std::string expected = "/home";
        std::string result = simplifyPath(path);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string path = "/home//foo/";
        std::string expected = "/home/foo";
        std::string result = simplifyPath(path);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string path = "/home/user/Documents/../Pictures";
        std::string expected = "/home/user/Pictures";
        std::string result = simplifyPath(path);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string path = "/../";
        std::string expected = "/";
        std::string result = simplifyPath(path);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string path = "/.../a/../b/c/../d/./";
        std::string expected = "/.../b/d";
        std::string result = simplifyPath(path);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
