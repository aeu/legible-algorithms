// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{
    func distance(from pointA:[Int], to pointB:[Int]) -> Int {
        let dx = pointA[0] - pointB[0]
        let dy = pointA[1] - pointB[1]
        return ( dx * dx ) + ( dy * dy )
    }
    
    func numberOfBoomerangs(_ points: [[Int]]) -> Int {
        var boomerangs = 0
        for from_index in 0..<points.count {
            var dcounts = [Int: Int]()
            for to_index in 0..<points.count {
                if from_index != to_index {
                    let dist = distance(from:points[from_index], to:points[to_index]);
                    dcounts[dist, default:0] += 1
                }
            }
            for (distance,count) in dcounts {
                if count > 1 {
                    boomerangs += count * ( count - 1 )
                }
            }
        }
        return boomerangs
    }

    enum TestCaseOne {
        static func run(_ testNumber: Int, with solution: Solution) {
            let points = [[0,0],[1,0],[2,0]]
            let expected = 2
            let actual = solution.numberOfBoomerangs(points)
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
            let points = [[1,1],[2,2],[3,3]]
            let expected = 2
            let actual = solution.numberOfBoomerangs(points)
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
            let points = [[1,1]]
            let expected = 0
            let actual = solution.numberOfBoomerangs(points)
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
        print("Leetcode #0447-number-of-boomerangs")
        let solution = Solution()
        Solution.TestCaseOne.run(1,   with: solution);
        Solution.TestCaseTwo.run(2 ,  with: solution);
        Solution.TestCaseThree.run(3, with: solution);
    }
}


Solution.main()

