// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82

class Solution
{

    /**
     * The read4 API is defined in the parent class Reader4.
     *     func read4(_ buf4: inout [Character]) -> Int;
     */

    func read(_ buf: inout [Character], _ n: Int) -> Int {
        var outstanding = n
        var total_read = 0
        var buf4: [Character] = Array(repeating: "\0", count: 4)
        while outstanding > 0 {
            let bytes_read = read4(&buf4)
            let limit = min( outstanding, bytes_read )
            for index in 0 ..< limit {
                buf[total_read+index] = buf4[index]
            }
            outstanding -= limit
            total_read  += limit
            if bytes_read < 4 {
                break
            }
        }
        return total_read
    }
    static func main()
    {
        print("Leetcode 0157-read-n-characters-given-read4")
    }
}


Solution.main()

