//
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//

import Foundation

struct Abc
{

    func getRow(_ rowIndex: Int) -> [Int]
    {
        print(String(format: "getRow called with an int of %d", rowIndex))
        if rowIndex == 0
        {
            return [1]
        }
        else if rowIndex == 1
        {
            return [1,1]
        }
        return []
    }
    
    static func main()
    {
        print("/leetcode/0119-pascals-triangle-ii/")
        let test_case = 1
        let expected = 2
        let result = 1
        print(String(format:"Test case %d : %@", test_case, (( expected == result ) ? "Pass" : "Fail" )))
            
        let fred = Abc()
        fred.getRow(3)
        // getRow(3)
    }
}


Abc.main()
