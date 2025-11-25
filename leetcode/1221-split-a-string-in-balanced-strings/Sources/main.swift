// The Swift Programming Language
// https://docs.swift.org/swift-book

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

