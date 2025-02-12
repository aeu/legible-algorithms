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
            "nationwide",
            "national",
            "awesome",
            "waterfall",
            "wednesday",
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
            "tomorrow",
        };
    for(auto current : search_words )
    {
        bool result = trie.search( current );
        std::cout << "search results for : " << current << ( result ? " true" : " false" ) << std::endl;  
    }


    return 0;
}
