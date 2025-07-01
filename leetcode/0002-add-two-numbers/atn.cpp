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


void dumpNode(ListNode *node)
{
    if( node == nullptr )
    {
        printf(" null node\n");
        return;
    }
    
    printf(" Value is %d\n", node->val );
    if( node->next != nullptr )
        printf(" Value of next is %d\n", node->next->val );
    else
        printf(" Value of next is null\n" );
        
}

class Solution
{
    private:
    protected:
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int val_one = 0;
        int val_two = 0;
        int digit   = 0;
        ListNode *node_one;
        ListNode *node_two;

        ListNode *retval = nullptr;
        ListNode *tail_node = nullptr;
        ListNode *temp_node = nullptr;

        node_one = l1;
        node_two = l2;

        while(( node_one != nullptr ) || ( node_two != nullptr ))
        {
            val_one = 0;
            val_two = 0;
            if( node_one != nullptr )
            {
                val_one = node_one->val;
            }
            if( node_two != nullptr )
            {
                val_two = node_two->val;
            }

            int sum = val_one + val_two + carry;
            carry = 0;
            if( sum >= 10 )
            {
                carry = 1;
                digit = sum % 10;
            }
            else
            {
                digit = sum;
            }

            temp_node  = new ListNode;
            temp_node->next = nullptr;
            temp_node->val = digit;

            if( retval == nullptr )
            {
                retval = temp_node;
                tail_node = temp_node;
            }
            else
            {
                tail_node->next = temp_node;
                tail_node = temp_node;
            }
            if( node_one != nullptr )
                node_one = node_one->next;
            if( node_two != nullptr )
                node_two = node_two->next;
        }
        if( carry )
        {
            temp_node  = new ListNode;
            temp_node->next = nullptr;
            temp_node->val = carry;
            tail_node->next = temp_node;
        }
            
        return retval;
    }
};


int main(int argc, char **argv)
{
    printf("Leetcode #2 : Add Two Numbers\n");
    Solution *lc_solution = new Solution();

    {
        ListNode l1_three  = ListNode(3, nullptr );
        ListNode l1_two    = ListNode(4, &l1_three );
        ListNode l1_one    = ListNode(2, &l1_two );
        
        ListNode l2_three  = ListNode(4, nullptr );
        ListNode l2_two    = ListNode(6, &l2_three );
        ListNode l2_one    = ListNode(5, &l2_two );
        
        dumpList(&l1_one);
        dumpList(&l2_one);
        ListNode *sum = lc_solution->addTwoNumbers( &l1_one, &l2_one );
        dumpList( sum );
        // !!! memory leak here, we need to free sum and everything in it.
    }
    {
        ListNode l2  = ListNode(0, nullptr );
        ListNode l1  = ListNode(0, nullptr );
        dumpList(&l1);
        dumpList(&l2);
        ListNode *sum = lc_solution->addTwoNumbers( &l1, &l2 );
        dumpList( sum );
        // !!! memory leak here, we need to free sum and everything in it.
    }

    {
        ListNode l1_seven  = ListNode(9, nullptr );
        ListNode l1_six    = ListNode(9, &l1_seven );
        ListNode l1_five   = ListNode(9, &l1_six );
        ListNode l1_four   = ListNode(9, &l1_five );
        ListNode l1_three  = ListNode(9, &l1_four );
        ListNode l1_two    = ListNode(9, &l1_three );
        ListNode l1_one    = ListNode(9, &l1_two );


        ListNode l2_four   = ListNode(9, nullptr );
        ListNode l2_three  = ListNode(9, &l2_four );
        ListNode l2_two    = ListNode(9, &l2_three );
        ListNode l2_one    = ListNode(9, &l2_two );

        dumpList( &l1_one );
        dumpList( &l2_one );
        // !!! memory leak here, we need to free sum and everything in it.
        ListNode *sum = lc_solution->addTwoNumbers( &l1_one, &l2_one );
        dumpList( sum );
    }
    
    return 0;
}
