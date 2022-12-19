// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <string>
#include <map>
#include <set>


void buildPermutations(std::vector <std::string> &components,
                       std::set    <std::string> &intermediates,
                       std::set    <std::string> &permutations)
{
    if( ! components.empty() )
    {
        auto current_component = components.back();
        components.pop_back();
        if( intermediates.empty() )
        {
            intermediates.insert( current_component );
            buildPermutations( components, intermediates, permutations );
        }
        else
        {
            std::string current_intermediate;
            std::set <std::string>::iterator intermediates_iterator;
            std::set <std::string> next_intermediates;
            for(intermediates_iterator = intermediates.begin();
                intermediates_iterator != intermediates.end();
                intermediates_iterator ++ )
            {
                current_intermediate = *intermediates_iterator;
                std::string::size_type siter = 0;
                bool done = false;
                while( ! done )
                {
                    auto new_intermediate = current_intermediate.insert( siter, current_component );
                    next_intermediates.insert( new_intermediate );
                    current_intermediate = *intermediates_iterator;
                    siter += current_component.length();
                    if( siter > current_intermediate.size() )
                    {
                        done = true;
                    }
                }
            }
            buildPermutations( components, next_intermediates, permutations );
        }
    }
    else
    {
        permutations = intermediates;
    }
}

const int permutationSequence(const int n, const int k)
{
    printf("Input: n = %d, k = %d\n", n, k);

    std::vector <std::string> components;
    std::set    <std::string> intermediates;
    std::set    <std::string> permutations;
  
    for(int index=1;index<=n;index++)
    {
        components.push_back( std::to_string( index ));
    }

    buildPermutations( components, intermediates, permutations );

    std::set<std::string>::iterator piter;
    piter = permutations.begin();
  
    if( k <= permutations.size() )
    {
        std::advance( piter, k-1 );
        auto selected = *piter;
        printf("%s\n", selected.c_str() );
    }
    return 0;
}

int main(int argc, char **argv)
{
    printf("LeetCode #60 - Permutation Sequence\n");
    permutationSequence(3,3);
    permutationSequence(4,9);
    permutationSequence(3,1);
}
