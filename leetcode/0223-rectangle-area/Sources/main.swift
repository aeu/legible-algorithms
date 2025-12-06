// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

import Foundation

class Solution
{
    func computeArea(_ ax1: Int, 
                     _ ay1: Int, 
                     _ ax2: Int, 
                     _ ay2: Int, 
                     _ bx1: Int, 
                     _ by1: Int, 
                     _ bx2: Int, 
                     _ by2: Int) -> Int {
        var computed_area = 0
        let ileft  = max(ax1,bx1)
        let ibot   = max(ay1,by1)
        let iright = min(ax2,bx2)
        let itop   = min(ay2,by2)
        var iarea = 0;
        if ( iright > ileft ) && ( itop > ibot ) {
            let width = iright - ileft;
            let height = itop - ibot;
            iarea = width * height;
        }

        let aarea = (ax2-ax1)*(ay2-ay1);
        let barea = (bx2-bx1)*(by2-by1);

        return aarea + barea - iarea;
    }


    static func main()
    {
        print("### leetcode/0223-rectangle-area")
        let sol = Solution()
        var test_case = 1
        var expected = 45
        var result = sol.computeArea(-3,0,3,4,0,-1,9,2)
        print("```")
        print("Expected: \(expected)")
        print("Result: \(result)")
        print("Test case \(test_case): \(expected == result ? "Pass" : "Fail")")
        print("```")


        test_case += 1
        expected = 16
        result = sol.computeArea(-2,-2,2,2,-2,-2,2,2)
        print("```")
        print("Expected: \(expected)")
        print("Result: \(result)")
        print("Test case \(test_case): \(expected == result ? "Pass" : "Fail")")
        print("```")
        
        
    }
}

Solution.main()

