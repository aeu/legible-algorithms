// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func missingNumber(_ nums: [Int]) -> Int {
        var missing_number = nums.count
        for (index,value) in nums.enumerated() {
            missing_number ^= index
            missing_number ^= value
        }
        return missing_number
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let nums = [3,0,1]
            let expected = 2
            let actual = solution.missingNumber(nums)
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
            let nums = [0,1]
            let expected = 2
            let actual = solution.missingNumber(nums)
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
            let nums = [9,6,4,2,3,5,7,0,1]
            let expected = 8
            let actual = solution.missingNumber(nums)
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
        print("Leetcode 0268-missing-number")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

