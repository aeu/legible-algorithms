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



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



void dumpNode(ListNode *node)
{
    if( node == nullptr )
    {
        printf("null node\n");
        return;
    }
    
    printf(" Value is %d\n", node->val );
    if( node->next != nullptr )
        printf(" Value of next is is %d\n", node->next->val );
}


void dumpList(ListNode *head )
{
    ListNode *current;
    current = head;
    int done = 0;
    int is_first = 1;
    printf("[");
    while( ! done  )
    {
        if( is_first )
        {
            is_first = 0;
        }
        else
        {
            printf(",");
        }
        printf("%d", current->val );
        if( current->next != nullptr )
            current = current->next;
        else
            done = 1;
    }
    printf("]\n");
}


class Solution
{
    private:
    protected:
    public:

    ListNode *swapNodes(ListNode *head,
                        ListNode *first_node,
                        ListNode *second_node )
    {
        ListNode *new_head = head;
        ListNode *current = head;
        ListNode *node_before_first  = nullptr;;
        ListNode *node_before_second = nullptr;
        
        ListNode *first_nodes_next   = nullptr;;
        ListNode *second_nodes_next  = nullptr;
        
        ListNode *previous      = nullptr;

        first_nodes_next = first_node->next;
        second_nodes_next = second_node->next;
        
        current = head;
        while(1)
        {
            if( current == first_node )
                node_before_first = previous;
            
            if( current == second_node )
                node_before_second = previous;

            if( current->next == nullptr )
                break;
            
            previous = current;
            current = current->next;
        }
        // We now have the following: 
        // first node
        // second node
        // node before first
        // node before second
        // first nodes next
        // second nodes next
        
        if( node_before_first != nullptr )
        {
            node_before_first->next = second_node;
        }
        //
        // This check prevents an infinite loop if the nodes are
        // directly following each other
        //
        if( first_nodes_next != second_node )
        {
            second_node->next = first_nodes_next;
        }
        else
        {
            second_node->next = first_node;
        }

        if( node_before_second != nullptr )
        {
            node_before_second->next = first_node;
        }

        //
        // This check prevents an infinite loop if the nodes are
        // directly following each other
        //
        if( second_nodes_next != first_node )
        {
            first_node->next = second_nodes_next;
        }
        else
        {
            first_node->next = second_node;
        }

        if( first_node == head )
            new_head = second_node;

        if( second_node == head )
            new_head = first_node;
        
        return new_head;
    }

    ListNode *getNthNode(ListNode *head, int n)
    {
        ListNode *retval = nullptr;
        ListNode *current = head;
        if( n == 0 )
            return head;
        
        while( n > 0 )
        {
            if( current->next != nullptr )
            {
                current = current->next;
                retval = current;
            }
            else
            {
                return nullptr;
            }
            n--;
        }
        return retval;
    }

    
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *new_head = head;
        ListNode *engine   = nullptr;
        ListNode *caboose  = nullptr;

        int basis         = 0;
        int done          = 0;
        int engine_index  = 0;
        int caboose_index = 0;

        while( ! done )
        {
            engine_index  = ( basis * k ) + k - 1;
            caboose_index = basis * k;
            engine        = getNthNode(new_head, engine_index );
            caboose       = getNthNode(new_head, caboose_index );

            if(( engine != nullptr ) && ( caboose != nullptr ))
            {
                new_head = swapNodes(new_head, engine, caboose );
            }
            else
            {
                break;
            }
            basis++;
        }
        return new_head;
    }
};


int main(int argc, char **argv)
{
    printf("Reverse Nodes in k-Group\n");
    Solution *lc_solution = new Solution();

    {
    
        ListNode five  = ListNode(5, nullptr );
        ListNode four  = ListNode(4, &five );
        ListNode three = ListNode(3, &four );
        ListNode two   = ListNode(2, &three );
        ListNode one   = ListNode(1, &two);
        
        ListNode *head = &one;
        dumpList( head );
        ListNode *new_head = lc_solution->reverseKGroup(head, 2 );
        dumpList( new_head );
    }
    {
        ListNode five  = ListNode(5, nullptr );
        ListNode four  = ListNode(4, &five );
        ListNode three = ListNode(3, &four );
        ListNode two   = ListNode(2, &three );
        ListNode one   = ListNode(1, &two);
        
        ListNode *head = &one;
        dumpList( head );
        ListNode *new_head = lc_solution->reverseKGroup(head, 3 );
        dumpList( new_head );
    }
}
