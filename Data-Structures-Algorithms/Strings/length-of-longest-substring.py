# https://leetcode.com/problems/longest-substring-without-repeating-characters/

# https://neetcode.io/problems/longest-substring-without-duplicates?list=neetcode150

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if (n < 2):
            return n
        maxCount = 0
        charSet = set()
        r = 0
        l = 0
        while(r < n):
            if (s[r] not in charSet):
                charSet.add(s[r])
                r += 1
                maxCount = max(maxCount, r - l)
            else:
                charSet.remove(s[l])
                l += 1
        return maxCount
        
    
    
                

            
        
