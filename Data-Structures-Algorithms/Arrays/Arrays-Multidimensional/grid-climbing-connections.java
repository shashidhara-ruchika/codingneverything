/*
https://leetcode.com/discuss/interview-question/system-design/1587350/Amazon-or-OA-Demo-or-Grid-Climbing

01011   3
01100   2
00000   0
01000   1

num of connections = 8, (lower level connection with 1 only)
*/

public class Solution {
    public int solution(List<List<Integer>> grid) {
        int connections = 0;
        List<Integer> nodes = new ArrayList<>();
        for (int row = 0; row < grid.size(); row++) {
            int count = 0;
            for (int col = 0; col < grid.get(0).size(); col++) {
                if (grid.get(row).get(col) == 1) {
                    count++;
                }
            }
            nodes.add(count);
        }

        for (int i = 0; i < nodes.size() - 1; i++) {
            for (int k = i + 1; k < nodes.size(); k++) {
                connections += i * k;
            }
        }

        return connections;
    }
}