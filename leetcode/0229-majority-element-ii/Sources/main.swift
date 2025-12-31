// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{

    func majorityElement(_ nums: [Int]) -> [Int] {
        var elements        = [Int]()
        var element_1       = 0
        var element_1_count = 0
        var element_2       = 0
        var element_2_count = 0
        let nover3 = nums.count / 3


        for current in nums {
            if current == element_1 {
                element_1_count += 1
            } else if current == element_2 {
                element_2_count += 1
            }
            else if element_1_count == 0 {
                element_1_count = 1
                element_1 = current
            } else if element_2_count == 0 {
                element_2_count = 1
                element_2 = current
            } else {
                element_1_count -= 1
                element_2_count -= 1
            }
        }

        element_1_count = 0
        element_2_count = 0

        for current in nums {
            if current == element_1 {
                element_1_count += 1
            } else if current == element_2 {
                element_2_count += 1
            }
        }
        if element_1_count > nover3  {
            elements.append(element_1)
        }
        if element_2_count > nover3  {
            elements.append(element_2)
        }
        print("\(element_1), \(element_2) : \(nover3)")
        print("\(element_1_count), \(element_2_count) : \(nover3)")
        return elements
    }
    
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let nums = [3,2,3]
            let expected = [3]
            let actual = solution.majorityElement(nums)
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
            let nums = [1]
            let expected = [1]
            let actual = solution.majorityElement(nums)
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
            let nums = [1,2]
            let expected = [1,2]
            let actual = solution.majorityElement(nums)
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
    enum TestCaseFour {
        static func run(_ testNumber: Int, with solution: Solution) {
            let nums = [1,2,1,2,2,3,3,1]
            let expected = [2,1]
            let actual = solution.majorityElement(nums)
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
        print("Leetcode 0229-majority-element-ii")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
        Solution.TestCaseFour.run(4, with: solution);
    }
}


Solution.main()

