// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation

class Solution
{
    func balancedStringSplit(_ s: String) -> Int
    {
        return 0;
    }

    static func main()
    {
        print("leetcode/1221-split-a-string-in-balanced-strings/")
        var test_case = 0
        var expected = 4
        let sol = Solution()
        var result = sol.balancedStringSplit("RLRRLLRLRL")
        print(String(format: "Test case %d : %@,", test_case, ((expected == result) ? "Pass" : "Fail")))
    }
}

Solution.main()


print("Hello, world!")
