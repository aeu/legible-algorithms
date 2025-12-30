// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    public class ListNode {
        public var val: Int
        public var next: ListNode?
        public init(_ val: Int) {
            self.val = val
            self.next = nil
        }
    }


    func dumpNodeList(_ node: ListNode?) {
        var curr = node;
        var first_time = false
        while curr != nil {
            print("\(curr!.val)")
            curr = curr!.next
            if first_time == false {
                print(" -> ")
                first_time = false
            }
        }
        print("\n")
    }
    func deleteNode(_ node: ListNode?) {
        guard let node = node, let next = node.next else { return }
        node.val = next.val
        node.next = next.next
    }
    
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {

            let four = ListNode(4)
            let five = ListNode(5)
            let one  = ListNode(1)
            let nine = ListNode(9)

            four.next = five;
            five.next = one;
            one.next  = nine;
            
            let expected = true
            let actual = false
            print("```")
            print("Test Case: \(testNumber)")
            solution.dumpNodeList(four)
            solution.deleteNode(five)
            solution.dumpNodeList(four)
            print()
            print("```")
        }
    }
    enum TestCaseTwo {
        static func run(_ testNumber: Int, with solution: Solution) {

            let four = ListNode(4)
            let five = ListNode(5)
            let one  = ListNode(1)
            let nine = ListNode(9)

            four.next = five;
            five.next = one;
            one.next  = nine;
            
            let expected = true
            let actual = false
            print("```")
            print("Test Case: \(testNumber)")
            solution.dumpNodeList(four)
            solution.deleteNode(one)
            solution.dumpNodeList(four)
            print()
            print("```")
        }
    }
    enum TestCaseThree {
        static func run(_ testNumber: Int, with solution: Solution) {
        }
    }
    
    static func main()
    {
        print("Leetcode #0237-delete-node-in-a-linked-list")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

