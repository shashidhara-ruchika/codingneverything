// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 class Solution {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (false) return lowestCommonAncestorIterativeTraversal(root, p, q);
        if (false) return lowestCommonAncestorRecursiveTraversal(root, p, q);
    }
    
    public TreeNode lowestCommonAncestorIterativeTraversal(TreeNode root, TreeNode p, TreeNode q) {
        int minNodeVal = Math.min(p.val, q.val);
        int maxNodeVal = Math.max(p.val, q.val);

        while (true) {
            if (root.val > maxNodeVal) {
                root = root.left;
            } else if (root.val < minNodeVal) {
                root = root.right;
            } else if (minNodeVal <= root.val && root.val <= maxNodeVal) {
                return root;
            }

        }
    }

    

    public TreeNode lowestCommonAncestorRecursiveTraversal(TreeNode root, TreeNode p, TreeNode q) {
        int minNodeVal = Math.min(p.val, q.val);
        int maxNodeVal = Math.max(p.val, q.val);

        if (root.val > maxNodeVal) {
            return lowestCommonAncestorRecursiveTraversal(root.left, p, q);
        } 

        if (root.val < minNodeVal) {
            return lowestCommonAncestorRecursiveTraversal(root.right, p, q);
        } 

        return root;

    }
}