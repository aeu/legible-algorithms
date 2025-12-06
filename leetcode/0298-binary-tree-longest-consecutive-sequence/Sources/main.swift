// -- Mode: swift; tab-width: 4; indent-tabs-mode: nil; --
//
// red82 // software
//
// This software may not be used or reproduced, in whole or in part,
// without the express written permission of red82


public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}


class Solution
{
    func buildTree(values: [Int?] ) -> TreeNode? {

        guard let rootVal = values[0] else {
            return nil
        }
        let root_node = TreeNode.init(rootVal);
        var nodes : [TreeNode] = []
        nodes.append(root_node)
        var index = 1
        let N = values.count
        while index < N {
            let current_node = nodes.removeFirst()
            if let val = values[index] {
                let left_node = TreeNode(val)
                current_node.left = left_node
                nodes.append(left_node)
            }
            index += 1
            if( index < N ) {
                if let val = values[index] {
                    let right_node = TreeNode(val)
                    current_node.right = right_node
                    nodes.append(right_node)
                }
            }
            index += 1
        }
        return root_node
    }
     

    func dfs(root node: TreeNode,
             depth currentDepth : Int,
             maxDepth maxDepth : inout Int) {

        maxDepth = max(maxDepth,currentDepth)
        
        if let left = node.left {
            var newDepth = 1
            if left.val == ( node.val + 1 ) {
                newDepth = currentDepth + 1
            }
            dfs( root: left, depth: newDepth, maxDepth: &maxDepth )
        }
        if let right = node.right {
            var newDepth = 1
            if right.val == ( node.val + 1 ) {
                newDepth = currentDepth + 1
            }
            dfs( root: right, depth: newDepth, maxDepth: &maxDepth )
        }
    }
    
    func longestConsecutive(_ root: TreeNode?) -> Int {
        var maxDepth = 1
        if let node = root {
            dfs( root:node, depth:1, maxDepth:&maxDepth );
        }
        return maxDepth
    }
    
    static func main()
    {
        var test_case = 1
        print("### leetcode/0298-binary-tree-longest-consecutive-sequence")
        let sol = Solution()


        print("```")
        var value_list : [Int?] = [1,nil,3,2,4,nil,nil,nil,5]
        var expected = 3
        var max = 1
        var tree_root = sol.buildTree(values:value_list)
        if let root = tree_root {
            max = sol.longestConsecutive(root)
        }

        print("Test Case \(test_case) : ")
        if max == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")


        test_case += 1
        value_list = [2,nil,3,2,nil,1]
        expected = 2
        max = 1
        tree_root = sol.buildTree(values:value_list)
        if let root = tree_root {
            max = sol.longestConsecutive(root)
        }
        print("```")
        print("Test Case \(test_case) : ")
        if max == expected {
            print("pass")
        } else {
            print("fail")
        }
        print("```")
        
    }
}

Solution.main()

