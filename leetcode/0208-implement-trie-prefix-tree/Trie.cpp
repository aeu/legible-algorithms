// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include "Trie.h"


TrieNode::TrieNode()
{
    is_terminal = false;
}


Trie::Trie()
{
    root = std::make_unique<TrieNode>();
}
    
void Trie::insert(std::string word)
{
    TrieNode *node = root.get();
    for(char current : word )
    {
        auto find_result = node->children.find(current);
        if( find_result == node->children.end() )
        {
            node->children[current] = std::make_unique<TrieNode>();
        }
        node = node->children[current].get();
    }
    node->is_terminal = true;
}

bool Trie::search(std::string word)
{
    TrieNode *node = root.get();
    for(char current : word )
    {
        auto find_result = node->children.find(current);
        if( find_result == node->children.end() )
        {
            return false;
        }
        node = node->children[current].get();
    }
    if( node->is_terminal )
        return true;
    return false;
}

bool Trie::startsWith(std::string prefix)
{
    return true;
}
