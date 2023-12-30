// https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

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

    public boolean isSymmetric(TreeNode root) {

        if (root == null) {
            return true;
        }

        Queue<TreeNode> ql = new LinkedList<TreeNode>();
        Queue<TreeNode> qr = new LinkedList<TreeNode>();

        ql.add(root.left);
        qr.add(root.right);

        TreeNode l, r;

        while (!ql.isEmpty()) {

            l = ql.poll();
            r = qr.poll();

            if (l == null && r == null) {
                continue;
            }
            if (l == null || r == null) {
                return false;
            }
            if (l.val != r.val) {
                return false;
            }

            ql.add(l.left);    qr.add(r.right);
            ql.add(l.right);   qr.add(r.left);
        }

        return true;
        
    }

}

class Solution2 {

    public boolean isSame(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        return p.val == q.val && isSame(p.left, q.right) && isSame(p.right, q.left);
    }

    public boolean isSymmetric(TreeNode root) {
        return isSame(root.left, root.right);
    }
}