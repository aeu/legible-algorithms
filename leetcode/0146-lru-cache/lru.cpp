// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


// Fundamentally the key to this solution is the moveToHead function.  Our goal
// here is to always have the most recently used entries at the front, so we do
// this using a doubly linked list.  When a node is used in any way, we move it
// to the head of the list.  If we do this every time any node is used, then the
// linked list will always have all the nodes in order of most recently to not
// recently used.

// the class has two componenes.  The first is an unordered map, which is used
// to actually store and find the nodes.  The second is the doubly linked list,
// which is used to keep track of which nodes have been most recently used.

class LRUCache
{
public:

    struct ListNode
    {
        std::shared_ptr<ListNode> next;
        std::shared_ptr<ListNode> prev;
        int key;
        int val;
    };

    int cache_size;
    std::unordered_map<int,std::shared_ptr<ListNode>> lookups;
    std::shared_ptr<ListNode> head;
    std::shared_ptr<ListNode> tail;
    
    LRUCache(int capacity)
    {
        cache_size = capacity;
    }

    void moveToHead(std::shared_ptr<ListNode> node)
    {
        if( node == head )
            return;

        if( head == nullptr )
        {
            head = node;
            tail = node;
            node->next = nullptr;
            node->prev = nullptr;
            return;
        }
        
        auto original_prev = node->prev;
        if (tail == node )
            tail = original_prev;
        
        auto prev = node->prev;
        auto next = node->next;
        node->next = head;
        
        if( prev != nullptr )
            prev->next = next;
        if( next != nullptr )
            next->prev = prev;
        
        head->prev = node;
        node->prev = nullptr;
        head = node;

    }

    void removeOldest()
    {
        if( tail != nullptr )
        {
            auto it = lookups.find(tail->key);
            if( it != lookups.end() )
                lookups.erase( it );
            
            std::shared_ptr<ListNode> tprev = tail->prev;
            if( tprev != nullptr )
            {
                tprev->next = nullptr;
                tail = tprev;
            }
            else
            {
                head = nullptr;
                tail = nullptr;
            }
        }
    }
    
    
    int get(int key)
    {
        auto it = lookups.find(key);
        if( it != lookups.end() )
        {
            std::shared_ptr<ListNode> curr = it->second;
            moveToHead( curr );
            return curr->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = lookups.find(key);
        if( it != lookups.end() )
        {
            std::shared_ptr<ListNode> existing = it->second;
            existing->val = value;
            moveToHead(existing);
        }
        else
        {
            std::shared_ptr<ListNode> just_added = std::make_shared<ListNode>();
            just_added->prev = nullptr;
            just_added->next = nullptr;
            just_added->val = value;
            just_added->key = key;

            // case 2
            if( lookups.size() < cache_size )
            {
                moveToHead(just_added);
                if( tail == nullptr )
                {
                    tail = just_added;
                }
            }
            else
            {
                removeOldest();
                moveToHead(just_added);
            }
            lookups[key] = just_added;
        }
        return; 
    }
};


int doWork()
{
    return 1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = doWork();
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
