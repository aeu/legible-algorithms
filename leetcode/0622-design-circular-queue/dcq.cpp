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

public:
    std::vector<int> data;
    int head;
    int tail;
    int size;

    MyCircularQueue(int k)
    {
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool enQueue(int value)
    {
        if( size < data.size() )
        {
            data[tail] = value;
            tail = ( tail + 1 ) % data.size();
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue()
    {
        if( size > 0 )
        {
            head = ( head + 1 ) % data.size();
            size--;
            return true;
        }
        return false;
    }
    
    int Front()
    {
        if( size == 0 )
            return -1;
        return data[head];
    }
    
    int Rear() {
        if( size == 0 )
            return -1;
        int rear_index =  ( tail - 1 + data.size() ) % data.size(); 
        return data[rear_index];
    }
    
    bool isEmpty() {
        if( size == 0 )
            return true;
        return false;
    }
    
    bool isFull() {
        if( size == data.size() )
            return true;
        return false;
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
