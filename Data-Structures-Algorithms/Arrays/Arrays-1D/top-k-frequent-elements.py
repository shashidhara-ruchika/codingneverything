# https://leetcode.com/problems/top-k-frequent-elements/description/

# https://neetcode.io/problems/top-k-elements-in-list?list=neetcode150

import heapq

class Solution: # Bucket or Couting Sort
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = dict()
        for n in nums:
            freq[n] = 1 + freq.get(n, 0)

        count_freq = [[] for i in range(len(nums) + 1)]

        for n, count in freq.items():
            count_freq[count].append(n)

        kfreq = []
        
        for cfi in range(len(count_freq) - 1, 0, -1):
            for n in count_freq[cfi]:
                kfreq.append(n)
                if len(kfreq) == k:
                    return kfreq
        
        return kfreq
        

class Solution2: # Hashmap & Priority Queue
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        freq = dict()
        for n in nums:
            freq[n] = 1 + freq.get(n, 0)
        
    
        pq = []
        for key, val in freq.items():
            heapq.heappush(pq, (-val, key)) # (comparision_val, original_num)
        
        kfreq = []
        i = 0
        while i < k and i < len(nums):
            comparision_val, original_num = heapq.heappop(pq)
            kfreq.append(original_num)
            i += 1
        
        return kfreq

        