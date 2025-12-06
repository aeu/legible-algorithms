// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

import Foundation

class Solution
{
    func reverseWords(_ s: inout [Character]) {
        var start = 0
        var end = s.count - 1
        while start < end {
            s.swapAt(start,end)
            start += 1
            end -= 1
        }
        // eulb si yks eht
        var slow = 0
        var N = s.count
        var fast = 0
        for fast in 0..<N {
            if s[fast] == " " {
                var l = slow;
                var r = fast - 1
                while l < r {   
                    s.swapAt(l,r)
                    l += 1
                    r -= 1
                }
                slow = fast + 1
            }
        }
        if slow < N {
            var l = slow
            var r = N - 1
            while l < r {
                s.swapAt(l, r)
                l += 1
                r -= 1
            }
        }
    }

    static func main()
    {
        print("### leetcode/0186-reverse-words-in-a-string-ii")
        let sol = Solution()

        var test_case = 0
        var expected = 4
        var candidate: [Character] = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]

        print("```")
        print(candidate)
        sol.reverseWords(&candidate)
        print(candidate)
        print("```")
    }
}

Solution.main()

