// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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
    int goodNodeCount;

    public int goodNodes(TreeNode root) {
        goodNodeCount = 0;

        int maxValInPath = Integer.MIN_VALUE;

        traverseWithMax(root, maxValInPath);

        return goodNodeCount;
    }

    public void traverseWithMax(TreeNode root, int maxValInPath) {
        if (root == null) {
            return;
        }

        if (maxValInPath <= root.val) {
            goodNodeCount++;
        }

        maxValInPath = Math.max(root.val, maxValInPath);

        traverseWithMax(root.left, maxValInPath);
        traverseWithMax(root.right, maxValInPath);
    }


    
    public int goodNodesPQ(TreeNode root) {

        goodNodeCount = 0;

        Comparator<TreeNode> descValTreeNodeComparator = (a, b) -> Integer.compare(b.val, a.val);

        PriorityQueue<TreeNode> pq = new PriorityQueue<>(descValTreeNodeComparator);
        
        traverseWithPathPQ(root, pq);

        return goodNodeCount;        
    }

    public void traverseWithPathPQ(TreeNode root, PriorityQueue<TreeNode> pq) {
        if (root == null) {
            return;
        }

        pq.add(root);

        TreeNode currentLargest = pq.peek();
        if (currentLargest.val <= root.val) {
            goodNodeCount++;
        } 
        traverseWithPathPQ(root.left, new PriorityQueue<>(pq));
        traverseWithPathPQ(root.right, new PriorityQueue<>(pq));
    }
}