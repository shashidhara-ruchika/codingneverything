// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

    public void inorderTraversalRecursive(TreeNode root, List<Integer> inorderTraversal) {
        if (root == null) {
            return;
        }

        inorderTraversalRecursive(root.left, inorderTraversal);
        inorderTraversal.add(root.val);
        inorderTraversalRecursive(root.right, inorderTraversal);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorderTraversal = new ArrayList<Integer>();
        inorderTraversalRecursive(root, inorderTraversal);
        return inorderTraversal;
    }

    public List<Integer> inorderTraversalIterative(TreeNode root) {
        List<Integer> inorderTraversal = new ArrayList<Integer>();

        Stack<TreeNode> s = new Stack<TreeNode>();

        TreeNode curr = root;

        while (!s.isEmpty() || curr != null ) {

            while(curr != null) {
                s.push(curr);
                curr = curr.left;
            }

            curr = s.pop();

            inorderTraversal.add(curr.val);

            curr = curr.right;


        }

        return inorderTraversal;
    }
}