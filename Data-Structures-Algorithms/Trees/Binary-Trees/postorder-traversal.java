// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    List<Integer> order = new ArrayList<>();

    public void postorderTraversalRecursive(TreeNode root) {
        if (root == null) return;

        postorderTraversalRecursive(root.left);
        postorderTraversalRecursive(root.right);
        order.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        postorderTraversalRecursive(root);
        return order;
    }

    public List<Integer> postorderTraversalIterative(TreeNode root) {
    }
}