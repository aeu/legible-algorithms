// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}


class Solution
{
    func addDigits(_ num: Int) -> Int {
        if num < 10 {
            return num
        }
        var lnum = num
        var sum = 0
        var done = 0
        while done == 0 {
            while lnum > 0 {
                sum += lnum % 10
                lnum = lnum / 10
            }
            if sum < 10 {
                done = 1
            }
            else {
                lnum = sum
                sum = 0
            }
        }
        return sum
    }

    static func main()
    {
        var test_case = 1
        print("### leetcode/0258-add-digits")
        let sol = Solution()


        print("```")
        var expected = 2
        var sum = sol.addDigits(38)
        print("Test Case \(test_case) : ")
        if sum == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")


        test_case += 1
        expected = 0
        sum = sol.addDigits(0)
        print("```")
        print("Test Case \(test_case) : ")
        if sum == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")
        
    }
}

Solution.main()

