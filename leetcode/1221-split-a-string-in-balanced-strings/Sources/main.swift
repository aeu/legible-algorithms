// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

import Foundation

class Solution
{
    func balancedStringSplit(_ s: String) -> Int
    {
        var balance = 0
        var total = 0
        for current_char in s {
            if current_char == "L" {
                balance = balance + 1
            }
            else {
                balance = balance - 1
            }
            if balance == 0 {
                total = total + 1
            }
        }
        return total
    }

    static func main()
    {
        print("### leetcode/1221-split-a-string-in-balanced-strings/")
        let sol = Solution()

        var test_case = 0
        var expected = 4
        var result = sol.balancedStringSplit("RLRRLLRLRL")
        print("```")
        print("Expected: \(expected)")
        print("Result: \(result)")
        print("Test case \(test_case): \(expected == result ? "Pass" : "Fail")")
        print("```")

        test_case += 1
        expected = 2
        print("```")
        print("Expected: \(expected)")
        print("Result: \(result)")
        result = sol.balancedStringSplit("RLRRRLLRLL")
        print("Test case \(test_case): \(expected == result ? "Pass" : "Fail")")
        print("```")

        test_case += 1
        expected = 1
        print("```")
        print("Expected: \(expected)")
        print("Result: \(result)")
        result = sol.balancedStringSplit("LLLLRRRR")
        print("Test case \(test_case): \(expected == result ? "Pass" : "Fail")")
        print("```")
    }
}

Solution.main()

