// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func shortestDistance(_ wordsDict: [String], _ word1: String, _ word2: String) -> Int {
        var word1_index = -1
        var word2_index = -1
        var min_distance = wordsDict.count
        for (index, currentWord ) in wordsDict.enumerated() {
            if currentWord == word1 {
                word1_index = index
            }
            if currentWord == word2 {
                word2_index = index
            }
            if word1_index != -1 && word2_index != -1 {
                var distance = min_distance
                if word1_index > word2_index {
                    distance = word1_index - word2_index
                } else {
                    distance = word2_index - word1_index
                }
                min_distance = min( distance, min_distance )
            }
        }
        return min_distance
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let word1 = "coding"
            let word2 = "practice"
            let words = ["practice","makes","perfect","coding","makes"]
            let expected = 3
            let actual = solution.shortestDistance(words, word1, word2)
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
            let word1 = "makes"
            let word2 = "coding"
            let words = ["practice","makes","perfect","coding","makes"]
            let expected = 1
            let actual = solution.shortestDistance(words, word1, word2)
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
        print("Leetcode 0243-shortest-word-distance")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

