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

class Solution
{
    private:
    protected:


    void buildPermutations(std::vector<std::string>& permutations,
                           std::vector<std::string>& intermediates,
                           std::vector<std::string>& words )
    {
        if( ! words.empty() )
        {
            std::string current_word = (std::string)words.back();
            words.pop_back();

            if( intermediates.empty() )
            {
                intermediates.push_back( current_word );
                buildPermutations( permutations,
                                   intermediates,
                                   words );
            }
            else
            {
                std::vector<std::string> next_intermediates;
                std::string current_intermediate;
                std::vector<std::string>::iterator inter_iter;
                for(inter_iter = intermediates.begin();
                    inter_iter != intermediates.end();
                    inter_iter++)
                {
                    current_intermediate = (std::string)*inter_iter;
                    std::string::size_type siter = 0;
                    int done = 0;
                    while( ! done  )
                    {
                        std::string next_intermediate = current_intermediate.insert( siter, current_word );
                        next_intermediates.push_back( next_intermediate );
                        siter += current_word.size();
                        current_intermediate = (std::string)*inter_iter;
                        if( siter > current_intermediate.size() )
                            done = 1;
                    }
                }
                buildPermutations( permutations,
                                   next_intermediates,
                                   words );
            }
        }
        else
        {
            permutations = intermediates;
        }
    }
    
    void findPermutations(std::vector<std::string>& permutations,
                          std::vector<std::string>& words)
    {
        std::vector<std::string> intermediates;
        buildPermutations( permutations, intermediates, words );
    }
    
    public:

    std::vector<int> findSubstring(std::string candidate, std::vector<std::string>& words)
    {
       std::vector<int>retval;
        std::vector<std::string> permutations;
        findPermutations( permutations, words );

        int count = 0;
        std::vector<std::string>::iterator viter;
        for( viter = permutations.begin();
             viter != permutations.end();
             viter++)
        {
            std::string current_permutation = (std::string)*viter;
            std::size_t found;
            int         start_position = 0;
            int         done = 0;
            while( ! done )
            {
                found = candidate.find( current_permutation, start_position ) ;
                if( found != std::string::npos )
                {
                    retval.push_back( found );
                    start_position += found;
                    start_position += 1;
                }
                else
                {
                    done = 1;
                }
            }
        }
        return retval;
    }

};


void dumpIndexes(std::vector<int> indexes )
{
    std::vector<int>::iterator indices_iterator;
    printf("[");
    int first = 1;
    for(  indices_iterator = indexes.begin();
          indices_iterator != indexes.end();
          indices_iterator++ )
    {
        if( ! first )
            printf(",");
        int current_index = (int)*indices_iterator;
        printf("%d",current_index );
        first = 0;
    }
    printf("]\n");
}


int main(int argc, char **argv)
{
    printf("Leetcode 0030 - Substring with Concatenation of All Words\n");
    Solution *lc_solution = new Solution();
    {
        std::vector<std::string> words;
        words.push_back("foo");
        words.push_back("bar");
        std::string s("barfoothefoobarman");
        std::vector<int> starting_indices;
        starting_indices = lc_solution->findSubstring(s, words);
        dumpIndexes( starting_indices );
    }

    {
        std::vector<std::string> words;
        words.push_back("word");
        words.push_back("good");
        words.push_back("best");
        words.push_back("word");
        std::string s("wordgoodgoodgoodbestword");
        std::vector<int> starting_indices;
        starting_indices = lc_solution->findSubstring(s, words);
        dumpIndexes( starting_indices );
    }

    {
        std::vector<std::string> words;
        words.push_back("bar");
        words.push_back("foo");
        words.push_back("the");
        std::string s("barfoofoobarthefoobarman");
        std::vector<int> starting_indices;
        starting_indices = lc_solution->findSubstring(s, words);
        dumpIndexes( starting_indices );
    }
}
