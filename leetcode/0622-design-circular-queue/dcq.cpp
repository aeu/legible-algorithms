// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

class MyCircularQueue {

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr),prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr),prev(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next),prev(nullptr) {}
};



public:
    int capacity;
    int current;
    ListNode *front;
    ListNode *rear;
    MyCircularQueue(int k)
    {
        capacity = k;
        current = 0;
        front = nullptr;
        rear = nullptr;
    }
    
    bool enQueue(int value)
    {
        if( current >= capacity )
            return false;
        ListNode *newval = new ListNode(value);
        if( current == 0 )
        {
            rear = newval;
            front = newval;
        }
        else
        {
            rear->prev = newval;
            newval->next = rear;
            rear = newval;
        }
        current++;
        return true;
    }
    
    bool deQueue()
    {
        if( current > 1 )
        {
            front = front->prev;
            current--;
            return true;
        }
        else if( current == 1 )
        {
            front = nullptr;
            rear = nullptr;
            current--;
            return true;
        }
        return false;
    }
    
    int Front()
    {
        if( current > 0 )
            return front->val;
        return -1;
    }
    
    int Rear() {
        if( current > 0 )
            return rear->val;
        return -1;
    }
    
    bool isEmpty() {
        return (current == 0);
    }
    
    bool isFull() {
        return ( current == capacity );
    }
};

int main(int argc, char **argv)
{
    std::cout << std::endl << "0622-design-circular-queue" << std::endl << std::endl;
    int test_case = 1;
    {
        MyCircularQueue *mcq = new MyCircularQueue(6);
        mcq->enQueue(6);
        mcq->Rear();
        mcq->Rear();
        mcq->deQueue();
        mcq->enQueue(5);
        std::cout << "rear " << mcq->Rear() << std::endl;
        mcq->deQueue();
        std::cout << "front " << mcq->Front() << std::endl;
        mcq->deQueue();
        mcq->deQueue();
        mcq->deQueue();
    }
    return 0;
}
