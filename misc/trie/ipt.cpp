// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <memory>
#include "Trie.h"


int main(int argc, char **argv)
{
    Trie trie;

    std::vector<std::string> words =
        { 
            "nachos",
            "fries",
            "burgers",
            "burro",
            "orange",
            "orwell",
            "orwellian",
            "orangutang",
            "oratory",
            "oration",
            "orchid",
            "burro",
            "burlap",
            "burnish",
            "nationwide",
            "national",
            "awesome",
            "awful",
            "waterfall",
            "wednesday",
            "wedding",
            "thursday",
            "tomorrow",
        };


    std::cout << "Insertion tests" << std::endl;
    for(auto current : words )
    {
        trie.insert( current );
    }

    std::vector<std::string> search_words =
        { 
            "nachos",
            "fries",
            "tacos",
            "nationwide",
            "xylophone",
            "awesome",
            "orchestra",
            "monday",
            "tuesday",
            "thursday",
            "tomahawk",
            "tomorrow",
        };

    std::cout << "Search Tests" << std::endl;
    
    for(auto current : search_words )
    {
        bool result = trie.search( current );
        std::cout << "search results for " << current << ( result ? " : true" : " : false" ) << std::endl;  
    }

    std::vector<std::string> starts_with_words =
        { 
            "nach",
            "xyz",
            "mo",
            "tue",
        };

    std::cout << "Prefix searches" << std::endl;
    
    for(auto current : starts_with_words )
    {
        bool result = trie.startsWith( current );
        std::cout << "Finds with results for " << current << ( result ? " : true" : " : false" ) << std::endl;  
    }

    std::cout << "Autocompletes" << std::endl;
    
    {
        std::string prefix = "we";
            std::vector<std::string> autocomplete = trie.autoComplete(prefix);
        std::cout << "Autocomplete with : " << prefix << std::endl;
        for( auto current : autocomplete )
        {
            std::cout << "-> " << current << std::endl;
        }
    }
    {
        std::string prefix = "or";
            std::vector<std::string> autocomplete = trie.autoComplete(prefix);
        std::cout << "Autocomplete with : " << prefix << std::endl;
        for( auto current : autocomplete )
        {
            std::cout << "-> " << current << std::endl;
        }
    }
    std::cout << "Autocompletes with max" << std::endl;
    
    {
        std::string prefix = "or";
        int max = 4;
        std::vector<std::string> autocomplete = trie.autoCompleteWithMax(prefix,max);
        std::cout << "Autocomplete with : " << prefix << " and a max of : " << max << std::endl;
        int index=0;
        for( auto current : autocomplete )
        {
            std::cout << index++ << "-> " << current << std::endl;
        }
    }
    return 0;
}
