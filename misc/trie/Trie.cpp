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
    std::cout << "inserting: " << word << std::endl;
    TrieNode *node = root.get();
    for(char current : word )
    {
        auto emplace_result = node->children.try_emplace(current,std::make_unique<TrieNode>());
        node = emplace_result.first->second.get();
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
            return false;
        node = find_result->second.get();
    }
    return node->is_terminal;
}

bool Trie::startsWith(std::string prefix)
{
    TrieNode *node = root.get();
    for( char current : prefix )
    {
        auto find_result = node->children.find(current);
        if( find_result == node->children.end() )
            return false;
        node = node->children[current].get();
    }
    return true;
}

void populateAllWords(TrieNode *node,
                      std::string current_word,
                      std::vector<std::string> &words)
{
    if( node->is_terminal )
        words.push_back(current_word);

    for(auto &pair : node->children )
    {
        TrieNode *child_node = pair.second.get();
        populateAllWords(child_node, current_word + pair.first, words );
    }
}

void populateAllWordsMap(TrieNode *node,
                         std::string current_word,
                         std::map<std::string, int> &words)
{
    if( node->is_terminal )
        words[current_word] = 1;

    for(auto &pair : node->children )
    {
        TrieNode *child_node = pair.second.get();
        populateAllWordsMap(child_node, current_word + pair.first, words );
    }
}

std::vector<std::string> Trie::autoComplete(std::string prefix)
{
    std::vector<std::string> completions;
    TrieNode *node = root.get();
    for(char current : prefix )
    {
        auto find_result = node->children.find(current);
        if( find_result == node->children.end() )
            return completions;
        node = node->children[current].get();
    }

    populateAllWords(node,prefix,completions);
    
    return completions;
}


/**
 * returns autocomplete search results, limited to a max count as well
 * as sorting the results alphabetically
 */
std::vector<std::string> Trie::autoCompleteWithMax(std::string prefix,
                                                   const int max_results)
{
    std::map<std::string,int> word_map;
    std::vector<std::string> completions;
    TrieNode *node = root.get();
    // walk down until we get to the node that represents the end of
    // the prefix
    for(char current : prefix )
    {
        auto find_result = node->children.find(current);
        if( find_result == node->children.end() )
            return completions;
        node = node->children[current].get();
    }

    populateAllWordsMap(node,prefix,word_map);

    // we know that maps are ordered by key, so take the first N
    // of them

    for(auto current_pair : word_map )
    {
        completions.push_back( current_pair.first );
        if( completions.size() >= max_results )
            break;
    }
    
    return completions;
}
