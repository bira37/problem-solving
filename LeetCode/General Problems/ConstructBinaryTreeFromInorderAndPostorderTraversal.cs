/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode build(int[] inorder, int[] postorder, int li, int ri, int lp, int rp){
        if(ri < li) return null;
        
        TreeNode root = new TreeNode();
        
        //last element of post is the root
        root.val = postorder[rp];
        
        int countLeft = 0;
        for(int i=li; i<=ri; i++){
            if(inorder[i] == postorder[rp]) break;
            countLeft++;
        }
        
        root.left = build(inorder, postorder, li, li+countLeft-1, lp, lp+countLeft-1);
        root.right = build(inorder, postorder, li+countLeft+1, ri, lp+countLeft, rp-1);
        return root;
    }
    
    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        return build(inorder, postorder, 0, inorder.Length-1, 0, postorder.Length-1);
    }
}
