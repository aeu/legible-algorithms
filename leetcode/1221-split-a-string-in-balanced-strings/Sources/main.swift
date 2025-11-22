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
        print("##leetcode/1221-split-a-string-in-balanced-strings/")
        let sol = Solution()
        
        var test_case = 0
        var expected = 4
        var result = sol.balancedStringSplit("RLRRLLRLRL")
        print(String(format: "Test case %d : %@,", test_case, ((expected == result) ? "Pass" : "Fail")))


        test_case += 1
        expected = 2
        result = sol.balancedStringSplit("RLRRRLLRLL")
        print(String(format: "Test case %d : %@,", test_case, ((expected == result) ? "Pass" : "Fail")))

        test_case += 1
        expected = 1
        result = sol.balancedStringSplit("LLLLRRRR")
        print(String(format: "Test case %d : %@,", test_case, ((expected == result) ? "Pass" : "Fail")))
    }
}

Solution.main()

