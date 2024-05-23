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

    public void traverseRightMost(TreeNode root, int level, List<Integer> result) {
        if (root == null) {
            return;
        }
        if (result.size() == level) {
            result.add(root.val);
        }
        traverseRightMost(root.right, level + 1, result);
        traverseRightMost(root.left, level + 1, result);
    }

    public List<Integer> rightSideView(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            traverseRightMost(root, 0, result);
            return result;
    }

    public List<Integer> rightSideViewFromBFS(TreeNode root) {
        List<List<Integer>> levelOrderTraversal = levelOrder(root);
        List<Integer> rightValues = new ArrayList<>();

        for (List<Integer> l : levelOrderTraversal) {
            rightValues.add(l.get(l.size() - 1));
        }

        return rightValues;
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        if (root == null) {
            return result;
        }

        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        while (!q.isEmpty()) {
            int currQSize = q.size();

            List<Integer> levelValues = new ArrayList<>();

            for (int i = 0; i < currQSize; i++) {
                TreeNode currentNode = q.remove();

                if (currentNode.left != null) {
                    q.add(currentNode.left);
                }

                if (currentNode.right != null) {
                    q.add(currentNode.right);
                }

                levelValues.add(currentNode.val);

            }

            result.add(levelValues);
        }       

        return result;
    }
}