// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

class Trie {
public:
    class TrieNode
    {
        
    public:
        
        TrieNode() { is_terminal = false; };
        bool is_terminal;
        std::unordered_map<char, std::unique_ptr<TrieNode>> children;
        
    protected:
    private:
    };

    std::unique_ptr<TrieNode> root;


    Trie() {
        root = std::make_unique<TrieNode>();     
    }
    
    void insert(string word) {
        TrieNode *node = root.get();
        for(char current : word )
        {
            auto emplace_result = node->children.try_emplace(current,std::make_unique<TrieNode>());
            node = emplace_result.first->second.get();
        }
        node->is_terminal = true;

    }
    
    bool search(string word) {
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
    
    bool startsWith(string prefix) {
        Trie::TrieNode *node = root.get();
        for( char current : prefix )
        {
            auto find_result = node->children.find(current);
            if( find_result == node->children.end() )
                return false;
            node = node->children[current].get();
        }
        return true;      
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
