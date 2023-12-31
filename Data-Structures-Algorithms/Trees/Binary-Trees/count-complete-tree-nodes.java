// https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150
// https://www.youtube.com/watch?v=CvrPf1-flAA

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
    public int countNodes2(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = 1;
        TreeNode lp = root.left;
        while (lp != null) {
            leftHeight++;
            lp = lp.left;
        }

        int rightHeight = 1;
        TreeNode rp = root.right;
        while (rp != null) {
            rightHeight++;
            rp = rp.right;
        }

        if (leftHeight == rightHeight) {
            return ((int) Math.pow(2, leftHeight)) - 1;
        }

        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}