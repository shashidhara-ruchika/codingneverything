/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

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
    public int kthSmallestRecursive(TreeNode root, int k) {
        List<Integer> l = new ArrayList<>();
        inorder(root, l);
        return l.get(k - 1);
    }

    public void inorder(TreeNode root, List<Integer> l) {
        if (root == null) return;
        inorder(root.left, l);
        l.add(root.val);
        inorder(root.right, l);
    }

    int ans = 0; int index = 0;

    public int kthSmallest(TreeNode root, int k) {
        ans = 0;
        index = 0;
        inorder(root, k);
        return ans;
    }

    public void inorder(TreeNode root, int k) {
        if (root == null) return;
        inorder(root.left, k);
        index++;
        if (k == index) {
            ans = root.val;
            return;
        }
        inorder(root.right, k);

    }

}