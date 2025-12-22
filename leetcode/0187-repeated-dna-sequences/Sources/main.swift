// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func findRepeatedDnaSequences(_ s: String) -> [String] {
        var repeated_sequences : [String] = []
        if s.count < 10 {
            return repeated_sequences
        }
        var dna_map: [String: Int] = [:]
        let chars = Array(s)
        for index in 0..<(s.count-9) {
            let sequence = String(chars[index..<(index+10)])
            dna_map[sequence, default: 0] += 1 
        }

        for (key, value) in dna_map {
            if value > 1 {
                repeated_sequences.append(key)
            }
        }
        return repeated_sequences
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
            let expected = ["AAAAACCCCC","CCCCCAAAAA"]
            let actual = solution.findRepeatedDnaSequences(s)
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
            let s = "AAAAAAAAAAAAA"
            let expected = ["AAAAAAAAAA"]
            let actual = solution.findRepeatedDnaSequences(s)
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
        print("Leetcode 0187-repeated-dna-sequences")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

