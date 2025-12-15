// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func isPowerOfTwo(_ n: Int) -> Bool {
        if n <= 0 {
            return false
        }
        if ( n & ( n - 1 ) ) == 0 {
            return true
        }
        return false
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            var expected = true
            var actual = solution.isPowerOfTwo(1)
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
            var expected = true
            var actual = solution.isPowerOfTwo(16)
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
            var expected = false
            var actual = solution.isPowerOfTwo(3)
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
        print("Leetcode 0231-power-of-two")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

