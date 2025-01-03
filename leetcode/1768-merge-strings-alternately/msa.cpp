// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <iostream>
#include <string>

std::string mergeStrings(std::string one,
                         std::string two)
{
    std::string::iterator oiter = one.begin();
    std::string::iterator titer = two.begin();
    std::string retval;
  
    while((oiter != one.end()) && (titer != two.end()))
    {
        retval += *oiter;
        retval += *titer;
        oiter++;
        titer++;
    }

    while( oiter != one.end() )
    {
        retval += *oiter;
        oiter++;
    }
    while( titer != two.end() )
    {
        retval += *titer;
        titer++;
    }
    return retval;
}


int main(int argc, char **argv)
{
    {
        std::string one = "abc";
        std::string two = "pqr";
        std::string merged = mergeStrings(one,two);
        std::cout << "merging : " << one << " and : " << two << " merged : " << merged << std::endl;
    }
    {
        std::string one = "ab";
        std::string two = "pqrs";
        std::string merged = mergeStrings(one,two);
        std::cout << "merging : " << one << " and : " << two << " merged : " << merged << std::endl;
    }
    {
        std::string one = "abcd";
        std::string two = "pq";
        std::string merged = mergeStrings(one,two);
        std::cout << "merging : " << one << " and : " << two << " merged : " << merged << std::endl;
    }
}

    
