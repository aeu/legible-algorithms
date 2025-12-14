// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution
{
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        let pre = ListNode(0)
        pre.next = head
        var slow = pre
        var fast = head
        while let node = fast {
            if node.val != val {
                slow.next = node
                slow = node
            }
            fast = node.next;
        }
        slow.next = nil;
        return pre.next
    }

    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let a = ListNode(1)
            let b = ListNode(2)
            let c = ListNode(6)
            let d = ListNode(3)
            let e = ListNode(4)
            let f = ListNode(5)
            let g = ListNode(6)
            a.next = b;
            b.next = c;
            c.next = d
            d.next = e;
            e.next = f;
            f.next = g
            
            print("```")
            print("Test Case: \(testNumber)")
            var node = solution.removeElements(a, 6)
            while let n = node {
                print(n.val, terminator: " ")
                node = n.next
            }
            print()
            print("```")
        }
    }
    enum TestCaseTwo {
        static func run(_ testNumber: Int, with solution: Solution) {
            
            print("```")
            print("Test Case: \(testNumber)")
            var node = solution.removeElements(nil, 1)
            while let n = node {
                print(n.val, terminator: " ")
                node = n.next
            }
            print()
            print("```")
        }
    }
    enum TestCaseThree {
        static func run(_ testNumber: Int, with solution: Solution) {
            let a = ListNode(7)
            let b = ListNode(7)
            let c = ListNode(7)
            let d = ListNode(7)
            a.next = b;
            b.next = c;
            c.next = d
            d.next = nil;
            
            print("```")
            print("Test Case: \(testNumber)")
            var node = solution.removeElements(a, 7)
            while let n = node {
                print(n.val, terminator: " ")
                node = n.next
            }
            print()
            print("```")
        }
    }
    static func main()
    {
        print("Leetcode 0203-remove-linked-list-elements")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

