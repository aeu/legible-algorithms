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
        printf(" Value of next is %d\n", node->next->val );
    else
        printf(" Value of next is null\n" );
        
}

void dumpList(ListNode *head )
{
    ListNode *current;
    current = head;
    int done = 0;
    while( ! done  )
    {
        printf("%d", current->val );
        if( current->next != nullptr )
            current = current->next;
        else
            done = 1;
    }
    printf("\n");
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
        printf("-p-\n");
        dumpNode(first_node);
        dumpNode(second_node);

        
        ListNode *zero  = head;
        ListNode *one   = zero->next;
        ListNode *two   = one->next;
        ListNode *three = two->next;
        ListNode *four  = three->next;

        printf("-0-\n");
        dumpNode(zero);
        dumpNode(one);
        dumpNode(two);
        dumpNode(three);
        dumpNode(four);

        
        ListNode *new_head  = head;
        ListNode *current   = head;

        ListNode *node_before_first  = nullptr;;
        ListNode *node_before_second = nullptr;
        
        ListNode *first_nodes_next   = nullptr;;
        ListNode *second_nodes_next  = nullptr;
        
        ListNode *previous      = nullptr;

        int done = 0;
        current = head;

        
        while( ! done )
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

        first_nodes_next = first_node->next;
        second_nodes_next = second_node->next;

        first_node->next = second_nodes_next;
        
        second_node->next = first_nodes_next;
        
        printf("-1-\n");
        dumpNode(zero);
        dumpNode(one);
        dumpNode(two);
        dumpNode(three);
        dumpNode(four);


        if( node_before_first != nullptr )
            node_before_first->next = second_node;
        if( node_before_second != nullptr )
            node_before_second->next = first_node;

        printf("-2-\n");
        dumpNode(zero);
        dumpNode(one);
        dumpNode(two);
        dumpNode(three);
        dumpNode(four);


        if( first_node == head )
            new_head = second_node;
        else if( second_node == head )
            new_head = first_node;
        

        printf("-3-\n");
        dumpNode(zero);
        dumpNode(one);
        dumpNode(two);
        dumpNode(three);
        dumpNode(four);

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

        int basis = 0;
        int done = 0;
        int engine_index;
        int caboose_index;

        engine  = getNthNode( new_head, 1 );
        caboose = getNthNode( new_head, 0 );

        ListNode *fred = swapNodes( new_head, engine, caboose );
        dumpList(fred);
        return nullptr;

        basis = 0;
        while( ! done )
        {
            engine_index = ( basis * k ) + k - 1;
            caboose_index = basis * k;
            printf("engine index: %d, caboose index: caboose_index: %d \n", engine_index, caboose_index );
            engine = getNthNode( head, engine_index );
            caboose = getNthNode( head, caboose_index );

            if( engine == nullptr )
                break;
            //                done = 1;

            if( caboose == nullptr )
                break;
            //                done = 1;

            ListNode *fred = swapNodes( new_head, engine, caboose );
            dumpList(fred);

            
            dumpNode( engine );
            dumpNode( caboose );
            basis++;

            // if(( engine != nullptr ) && ( caboose != nullptr ))
            // {
            //     new_head = swapNodes(new_head, engine, caboose );
            //     dumpList( new_head );
            // }
            // else
            // {
            //     break;
            // }
        }
        return new_head;

        
#if 0

        
        engine = getNthNode(new_head, 1 );
        caboose = getNthNode(new_head, 0 );

        printf("engine->val = %d\n",  engine->val );
        printf("caboose->val = %d\n", caboose->val );
        
        new_head = swapNodes(new_head, engine, caboose );
        //        dumpList(new_head );
        
        return new_head;
        
        
        return new_head;
#endif    
        return new_head;
    }
};


int main(int argc, char **argv)
{
    printf("Reverse Nodes in k-Group\n");
    Solution *lc_solution = new Solution();

    ListNode five  = ListNode(5, nullptr );
    ListNode four  = ListNode(4, &five );
    ListNode three = ListNode(3, &four );
    ListNode two   = ListNode(2, &three );
    ListNode one   = ListNode(1, &two);

    ListNode *head = &one;
    ListNode *new_head = lc_solution->reverseKGroup(head, 2 );
    
    return 0;
    
#if 0

    ListNode *new_head = lc_solution->reverseKGroup(head, 2 );

    


    
    ListNode *test;
    


    
    test = lc_solution->getNthNode(&one, 3 );
    printf("Node 3 = %d\n", test->val );
    test = lc_solution->getNthNode(&one, 1 );
    printf("Node 1 = %d\n", test->val );
    test = lc_solution->getNthNode(&one, 0 );
    printf("Node 0 = %d\n", test->val );

    test = lc_solution->getNthNode(&one, 6 );
    if( test == nullptr )
        printf("6 was a null\n");

    
    

    //    ListNode new_head = (ListNode)*lc_solution->swapNodes(&one, &three, &five );
    ListNode new_head = (ListNode)*lc_solution->swapNodes(&one, &one, &five );
    
    dumpList(&new_head);
#endif    
}
