// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

import java.util.*;

class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        List<Worker> workers = new ArrayList<>();
        
        // Sort by ratio increasingly
        Collections.sort(workers, (a, b) -> (a.ratio - b.ratio));
        int minCost = Integer.MAX_VALUE;
        
        // Maxheap always pop highest quality
        PriorityQueue<Worker> maxHeap = new PriorityQueue<>((a, b) -> (b.quality - a.quality));
        
        int totalQuality = 0;
        for (Worker worker : workers) {
            maxHeap.offer(worker);
            totalQuality += worker.quality;
            
            if (maxHeap.size() > K) {
                Worker w = maxHeap.poll();
                totalQuality -= w.quality;
            } 
            
            if (maxHeap.size() == K) {
                minCost = Math.min(totalQuality * worker.ratio, minCost);
            }
        }
        
        return minCost;
    }
    
    class Worker {
        int quality;
        int wage;
        int ratio;
        
        public Worker(int quality, int wage) {
            this.quality = quality;
            this.wage = wage;
            ratio = wage[i] / quality[i];
        }
    }
}