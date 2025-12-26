// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{

    func backtrack(solutionSet solutions:inout [[Int]],
                   currentSolution solution:inout [Int],
                   currentSum current:Int,
                   startingAt start:Int,
                   toSum sum: Int,
                   usingDigits using:Int ) {

        if current > sum {
            return
        }
        if solution.count == using {
            if current == sum {
                solutions.append(solution)
            }
            return
        }
        if start > 9 {
            return
        }
        for index in start...9 {
            solution.append(index)
            backtrack(solutionSet:&solutions,
                      currentSolution:&solution,
                      currentSum:current+index,
                      startingAt:index+1,
                      toSum:sum,
                      usingDigits:using)
            solution.removeLast()
        }
    }
    
    func combinationSum3(_ k: Int, _ n: Int) -> [[Int]] {
        var solutions : [[Int]] = []
        var solution  :[Int] = []
        
        backtrack(solutionSet:&solutions,
                  currentSolution:&solution,
                  currentSum:0,
                  startingAt:1,
                  toSum:n,
                  usingDigits:k)
        
        return solutions
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let k = 3
            let n = 7
            let expected = [[1,2,4]]
            let actual = solution.combinationSum3(k,n)
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
            let k = 3
            let n = 9
            let expected = [[1,2,6],[1,3,5],[2,3,4]]
            let actual = solution.combinationSum3(k,n)
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
            let k = 3
            let n = 1
            let expected = [[Int]]()
            let actual = solution.combinationSum3(k,n)
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
            let k = 9
            let n = 45
            let expected = [[1,2,3,4,5,6,7,8,9]]
            let actual = solution.combinationSum3(k,n)
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
        print("Leetcode 0216-combination-sum-iii")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
        Solution.TestCaseFour.run(4, with: solution);
    }
}


Solution.main()

