// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func canPermutePalindrome(_ s: String) -> Bool {
        var counts = Array(repeating: 0, count: 26)
        for current_char in s {
            let index = Int(current_char.asciiValue! - Character("a").asciiValue! + 1)
            counts[index] = counts[index] + 1
        }
        var num_odds = 0
        for current_count in counts {
            if ( current_count & 1 ) != 0 {
                num_odds += 1
                if num_odds > 1 {
                    return false
                }
            }
        }
        return true
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "code"
            let expected = false
            let actual = solution.canPermutePalindrome(s)
            print("```")
            print("Test Case: \(testNumber)")
            if expected == actual {
                print("PASS")
            } else {
                print("FAIL")
            }
            print()
            print("```")
        }
    }
    enum TestCaseTwo {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "aab"
            let expected = true
            let actual = solution.canPermutePalindrome(s)
            print("```")
            print("Test Case: \(testNumber)")
            if expected == actual {
                print("PASS")
            } else {
                print("FAIL")
            }
            print()
            print("```")
        }
    }
    enum TestCaseThree {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "carerac"
            let expected = true
            let actual = solution.canPermutePalindrome(s)
            print("```")
            print("Test Case: \(testNumber)")
            if expected == actual {
                print("PASS")
            } else {
                print("FAIL")
            }
            print()
            print("```")
        }
    }
    
    static func main()
    {
        print("Leetcode 0243-shortest-word-distance")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

