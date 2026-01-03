// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{

    func heapsAlgorithm(_ chars: [Character]) -> Set<String> {
        var local = chars
        let N = local.count
        var control = [Int](repeating: 0, count: N)
        var result: Set<String> = [String(local)]

        var index = 0
        while index < N {
            if control[index] < index {
                if (index % 2) == 0 {
                    local.swapAt(0,index)
                } else {
                    local.swapAt(control[index],index)
                }
                result.insert(String(local))
                control[index] += 1
                index = 0
            } else {
                control[index] = 0
                index += 1
            }
        }
        return result
    }
    
    func generatePalindromes(_ s: String) -> [String] {
        
        var palindromes = [String]()
        var chars = [Character]()
        var counts = [Int](repeating: 0, count: 26)
        for current in s {
            let index = Int(current.asciiValue! - Character("a").asciiValue!)
            counts[index] += 1
        }
        var num_odds = 0
        var odd_char: Character? = nil
        for index in 0..<26 {
            var current_count = counts[index]
            if current_count == 0 {
                continue
            }
            let cchar = Character(UnicodeScalar(index + Int(Character("a").asciiValue!))!)
            if current_count % 2 != 0 {
                odd_char = cchar
                num_odds += 1
                if num_odds > 1 {
                    return palindromes
                }
            }
            current_count /= 2
            for _ in 0..<current_count {
                chars.append(cchar)
            }
        }
        var palindrome = ""
        let permutations = heapsAlgorithm(chars)
        for current in permutations {
            if odd_char != nil {
                palindrome = current + String(( odd_char ?? Character("") )) + String(current.reversed())
            } else { 
                palindrome = current + String(current.reversed())
            }
            palindromes.append(palindrome)
        }
//        for (index,current) in palindromes.enumerated() {
//            print("\(index) : \(current)")
//        }
        return palindromes
    }
    
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let s = "aabb"
            let expected = ["abba","baab"]
            let actual = solution.generatePalindromes(s)
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
    }
}


Solution.main()

