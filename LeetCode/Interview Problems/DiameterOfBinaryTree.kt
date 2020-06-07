/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    
    fun go(r : TreeNode?) : IntArray {
        if(r == null) return intArrayOf(0,0,0, 0)
        
        var nw = go(r.left)
        var nw2 = go(r.right)
        
        var ans = intArrayOf(nw[2]+1, nw2[2]+1, maxOf(nw2[2], nw[2])+1, 0)
        
        ans[3] = maxOf(nw[3], maxOf(nw2[3], maxOf(0, ans[0] + ans[1] - 2)))
        return ans
        
    }
    
    fun diameterOfBinaryTree(root: TreeNode?): Int {
        var (a,b, c, d) = go(root)
        return maxOf(0,d)
    }
}
