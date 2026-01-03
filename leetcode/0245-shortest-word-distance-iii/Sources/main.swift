// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{

    func shortestWordDistance(_ wordsDict: [String], _ word1: String, _ word2: String) -> Int {
        let areSame = ( word2 == word1 )
        var minDistance = wordsDict.count
        var word1_pos = -1
        var word2_pos = -1
        for (index,current) in wordsDict.enumerated() {
            if current == word1 {
                if areSame {
                    if word1_pos != -1 {
                        minDistance = min( minDistance, abs( index - word1_pos ))
                    }
                    word1_pos = index
                }
                else {
                    word1_pos = index
                }
            } else if current == word2 {
                word2_pos = index
            }
            if !areSame && word1_pos != -1 && word2_pos != -1 {
                minDistance = min( minDistance, abs( word2_pos - word1_pos ))
            }
        }
        return minDistance
    }

    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let wordsDict = ["practice", "makes", "perfect", "coding", "makes"]
            let word1 = "makes"
            let word2 = "coding"
            let expected = 1
            let actual = solution.shortestWordDistance(wordsDict,word1,word2)
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
            let wordsDict = ["practice", "makes", "perfect", "coding", "makes"]
            let word1 = "makes"
            let word2 = "makes"
            let expected = 3
            let actual = solution.shortestWordDistance(wordsDict,word1,word2)
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
        print("Leetcode #")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

