// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


class Solution
{

    func letterToNumber(_ letter: Character) -> Int {
        let baseScalar = Character("A").unicodeScalars.first!.value
        let letterScalar = letter.unicodeScalars.first!.value
        return Int(letterScalar - baseScalar) + 1
    }
    
    func titleToNumber(_ columnTitle: String) -> Int {
        var number = 0
        for currentChar in columnTitle {
            number = ( number * 26 ) + letterToNumber(currentChar)
        }
        return number
    }
    
    static func main()
    {
        var test_case = 1
        print("### leetcode/0171-excel-sheet-column-number")
        let sol = Solution()


        print("```")
        var actual = 1

        var expected = 1
        actual = sol.titleToNumber("A")
        print("Test Case \(test_case) : ")
        if actual == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")
        test_case += 1

        expected = 28
        actual = sol.titleToNumber("AB")
        print("Test Case \(test_case) : ")
        if actual == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")
        test_case += 1

        expected = 701
        actual = sol.titleToNumber("ZY")
        print("Test Case \(test_case) : ")
        if actual == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")
        test_case += 1
    }
}

Solution.main()

