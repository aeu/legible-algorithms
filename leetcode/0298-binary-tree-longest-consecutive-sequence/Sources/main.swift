// The Swift Programming Language
// https://docs.swift.org/swift-book


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
        var root_node = TreeNode.init(rootVal);
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
             depth currentDepth : Int ) {

        print("\(currentDepth) : \( node.val  )")
        if let left = node.left {
            dfs( root: left,
                 depth: currentDepth + 1 )
        }
        if let right = node.right {
            dfs( root: right,
                 depth: currentDepth + 1 )
        }

        if node.left == nil && node.right == nil {
            print("end of the line \(node.val)")
        }
    }
    
    func longestConsecutive(_ root: TreeNode?) -> Int {
        return 0
    }
    
    static func main()
    {
        print("### leetcode/0298-binary-tree-longest-consecutive-sequence")
        let sol = Solution()


        var value_list : [Int?] = [1,nil,3,2,4,nil,nil,nil,5]
        var expected = 3
        var tree_root = sol.buildTree(values:value_list);
        if let root = tree_root {
            sol.dfs(root:root, depth: 0 )
        }
        var test_case = 0

        print("```")
        print("```")
    }
}

Solution.main()



print("Hello, world!")
