// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <memory>
#include <iostream>

class ListNode : public std::enable_shared_from_this<ListNode>
{
public:

    ListNode();
    ListNode(const int node_value);
    ListNode(const int node_value, std::shared_ptr<ListNode> next_value);
    void dumpNodes();
    std::shared_ptr<ListNode> getNext();
    std::shared_ptr<ListNode> setNext(std::shared_ptr<ListNode> next_value);
    
    int getValue();
    int setValue(const int new_value);
    
    
protected:

    int value;
    std::shared_ptr<ListNode> next;
    
private:
  
};
