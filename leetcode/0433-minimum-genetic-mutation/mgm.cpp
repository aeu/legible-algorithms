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
#include <unordered_map>
#include <queue>


bool isValidMutation(std::string start_gene, std::string end_gene)
{
    int differences = 0;
    for(int index=0;index<start_gene.size();index++)
    {
        if( start_gene[index] != end_gene[index] )
        {
            differences++;
            if( differences > 1 )
                return false;
        }
    }
    return true;
}

int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank)
{
    struct Mutation {
        int steps;
        std::string gene;
    };
    std::queue<Mutation> m_queue;
    std::unordered_set<std::string> visited;

    m_queue.push( { 0, startGene } );
    visited.insert(startGene);
    while( ! m_queue.empty() )
    {
        Mutation current = m_queue.front();
        m_queue.pop();
        
        if( current.gene == endGene )
            return current.steps;
        
        for( auto candidate : bank )
        {
            if( visited.find( candidate ) == visited.end () )
            {
                if( isValidMutation ( current.gene, candidate ))
                {
                    visited.insert(candidate);
                    m_queue.push( { ( current.steps + 1 ), candidate });
                }
            }
        }
    }
    return -1;
}


int main(int argc, char **argv)
{
    {
        std::string start_gene = "AACCGGTT";
        std::string end_gene   = "AACCGGTA";
        std::vector<std::string> bank = { "AACCGGTA" };
        int expected = 1;
        int result = minMutation( start_gene, end_gene, bank );
        std::cout << "Test case : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string start_gene = "AACCGGTT";
        std::string end_gene   = "AAACGGTA";
        std::vector<std::string> bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
        int expected = 2;
        int result = minMutation( start_gene, end_gene, bank );
        std::cout << "Test case : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    
}
