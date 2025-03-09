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

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node *cloneGraph(Node* node)
{
    if( node == nullptr )
        return nullptr;
    
    std::queue<Node *> clone_queue;
    std::unordered_map<Node *, Node *> node_clones;

    Node *root = new Node( node->val );
    node_clones[node] = root;
    
    clone_queue.push( node );
    while( ! clone_queue.empty() )
    {
        Node *current = clone_queue.front();
        clone_queue.pop();

        for(auto nei : current->neighbors )
        {
            Node *ntemp;
            if( node_clones.find( nei ) == node_clones.end() )
            {
                ntemp = new Node( nei->val );
                node_clones[ nei ] = ntemp;
                clone_queue.push( nei );
            }
            else
            {
                ntemp = node_clones[nei];
                
            }
            node_clones[current]->neighbors.push_back( ntemp );
        }
    }
    return root;
}

int main(int argc, char **argv)
{
    return 0;
}
