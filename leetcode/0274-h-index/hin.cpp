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

void dumpValues(const std::vector<int> &values )
{
    bool first_time = true;
    std::cout << "[";
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


int hIndex(std::vector<int>& citations)
{
    std::sort(citations.begin(), citations.end());
    int paper_count = 1;
    int h_index = 0;
    for(int index=citations.size()-1;index>=0;index--)
    {
        int num_citations = citations[index];
        if( num_citations >= paper_count )
        {
            h_index++;
            paper_count++;
        }
        else
            break;
    }
    dumpValues( citations );
    return h_index;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #274 - H-Index" << std::endl << std::endl;
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::vector<int> citations = {3,0,6,1,5};
        int hindex = hIndex(citations);
        std::cout << "hIndex: " << hindex << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::vector<int> citations = {1,3,1};
        int hindex = hIndex(citations);
        std::cout << "hIndex: " << hindex << std::endl;
    }
    return -1;
}
