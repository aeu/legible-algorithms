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
    for(auto current : starts_with_words )
    {
        bool result = trie.startsWith( current );
        std::cout << "Finds with results for " << current << ( result ? " : true" : " : false" ) << std::endl;  
    }


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
        std::string prefix = "bur";
            std::vector<std::string> autocomplete = trie.autoComplete(prefix);
        std::cout << "Autocomplete with : " << prefix << std::endl;
        for( auto current : autocomplete )
        {
            std::cout << "-> " << current << std::endl;
        }
    }
    return 0;
}
