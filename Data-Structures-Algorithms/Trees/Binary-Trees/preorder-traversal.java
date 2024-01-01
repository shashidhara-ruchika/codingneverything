// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

    List<Integer> order = new ArrayList();

    public void preorderRecursiveTraversal(TreeNode root) {
        if (root == null) return;

        order.add(root.val);
        preorderRecursiveTraversal(root.left);
        preorderRecursiveTraversal(root.right);
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        preorderRecursiveTraversal(root);
        return order;
    }

    public List<Integer> preorderTraversalIterative(TreeNode root) {

        Stack<TreeNode> s = new Stack<>();

        if (root != null) {
            s.push(root);
        }

        TreeNode curr;

        while (!s.isEmpty()) {

           curr = s.pop();

           order.add(curr.val);

           if (curr.right != null) {
                s.push(curr.right);
           }

           if (curr.left != null) {
                s.push(curr.left);
           }

        }

        return order;
    }
}