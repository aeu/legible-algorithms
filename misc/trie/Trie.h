// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#ifndef TRIE_H
#define TRIE_H

#import <string>
#import <vector>
#import <memory>
#import <map>
#import <unordered_map>



class TrieNode
{

public:

    TrieNode();
    bool is_terminal;
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;

protected:
private:
    

};



class Trie
{

public:

    Trie();
    void insert(std::string word);
    bool search(std::string word);
    bool startsWith(std::string prefix);
    std::vector<std::string> autoComplete(std::string prefix);

protected:
private:

    std::unique_ptr<TrieNode> root;

};
#endif
