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
    fun zigzagLevelOrder(root: TreeNode?): List<List<Int>> {
        if(root == null) return listOf()
        var ans : MutableList<List<Int>> = mutableListOf<List<Int>>()
        var q : MutableList<TreeNode> = mutableListOf(root)
        var even : Boolean = true
        while(q.size > 0){
            var nq : MutableList<TreeNode>  = mutableListOf()
            var lt : MutableList<Int> = mutableListOf()
            even = !even
            for(x in q){
                lt.add(x.`val`)
                if(x.left != null) nq.add(x.left)
                if(x.right != null) nq.add(x.right)
            }
            if(even){
                lt.reverse()
            }
            q = nq
            ans.add(lt.toList())
        }
        return ans.toList()
    }
}
