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
        var arr: [Int] = []
        arr.append(1);
        for index in 0..<rowIndex {
            let current = arr.last!
            let next = (current * (rowIndex - index )) / ( index + 1 ) 
            arr.append(next)
        }
        return arr
    }
    
    static func main()
    {
        print("/leetcode/0119-pascals-triangle-ii/")
            
        let fred = Abc()
        var row = fred.getRow(0)
        print(row.map(String.init).joined(separator: " "))

        row = fred.getRow(1)
        print(row.map(String.init).joined(separator: " "))

        row = fred.getRow(2)
        print(row.map(String.init).joined(separator: " "))

        row = fred.getRow(3)
        print(row.map(String.init).joined(separator: " "))

    }
}


Abc.main()
