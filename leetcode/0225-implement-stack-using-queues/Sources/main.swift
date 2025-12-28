// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


class MyStack {

    var q1: [Int] = []
    var q2: [Int] = []
    
    init() {
        
    }
    
    func push(_ x: Int) {
        q2.append(x)
        while q1.isEmpty == false {
            q2.append( q1.removeFirst() )
        }
        swap(&q1,&q2)
    }
    
    func pop() -> Int {
        return q1.removeFirst()
    }
    
    func top() -> Int {
        return q1.first ?? -1
    }
    
    func empty() -> Bool {
        return q1.isEmpty
    }
}

class Solution
{
    static func main()
    {
        print("Leetcode 0225-implement-stack-using-queues")
        let myStack = MyStack()
        myStack.push(1);
        myStack.push(2);
        myStack.top();
        myStack.pop();
        myStack.empty();
    }
}


Solution.main()

