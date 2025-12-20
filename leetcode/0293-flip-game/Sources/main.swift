// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func generatePossibleNextMoves(_ currentState: String) -> [String] {
        var flipped: [String] = []
        if currentState.count < 2 {
            return flipped
        }
        let random_access = Array( currentState )
        for index in 0..<currentState.count - 1 {
            if random_access[index] == "+" && random_access[index+1] == "+" {
                var mutable = random_access
                mutable[index] = "-"
                mutable[index+1] = "-"
                let modified = String(mutable)
                flipped.append( modified )
            }
        }
        return flipped
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "++++"
            let expected = ["--++","+--+","++--"]
            let actual = solution.generatePossibleNextMoves(s)
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
            let s = "+"
            let expected: [String] = []
            let actual = solution.generatePossibleNextMoves(s)
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
        }
    }
    
    static func main()
    {
        print("Leetcode /0293-flip-game")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

