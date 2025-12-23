// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func isReflected(_ points: [[Int]]) -> Bool {

        struct Point: Hashable {
            let x: Int
            let y: Int
        }
        
        var min_x = Int.max
        var max_x = Int.min
        var point_dictionary       : [ Point : Int ] = [:]
        var transformed_dictionary : [ Point : Int ] = [:]
        for current_point in points {
            min_x = min( min_x, current_point[0] )
            max_x = max( max_x, current_point[0] )
            point_dictionary[Point(x:current_point[0],y:current_point[1]),default:0] += 1
        }

        let midx = Double(min_x + max_x) / 2.0

        for current_point in points {
            let transy = current_point[1]
            let transx = Int(2.0 * midx - Double(current_point[0]))
            let transformed = Point( x:transx, y:transy )
            transformed_dictionary[transformed,default:0] += 1
            if point_dictionary[transformed] == nil {
                return false
            }
        }
        for (key,count) in point_dictionary {
            if transformed_dictionary[key] == nil {
                return false
            }
        }
        return true
    }
    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let points = [[1,1],[-1,1]]
            let expected = true
            let actual = solution.isReflected(points)
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
            let points = [[1,1],[-1,-1]]
            let expected = false
            let actual = solution.isReflected(points)
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
            let points = [[-16,1],[16,1],[16,1]]
            let expected = true
            let actual = solution.isReflected(points)
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
        print("Leetcode 0356-line-reflection")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

