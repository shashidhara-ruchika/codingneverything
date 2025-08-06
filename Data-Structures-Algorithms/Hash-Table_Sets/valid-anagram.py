# https://leetcode.com/problems/valid-anagram/description/

# https://neetcode.io/problems/is-anagram?list=neetcode150

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_freq = dict()
        t_freq = dict()

        if len(s) != len(t):
            return False

        for s_char in s:
            s_freq[s_char] = 1 + s_freq.get(s_char, 0)
        
        for t_char in t:
            t_freq[t_char] = 1 + t_freq.get(t_char, 0)

        for s_key, s_val in s_freq.items():
            t_val = t_freq.get(s_key, 0)
            if t_val != s_val:
                return False
        
        return True

        