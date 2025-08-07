# https://leetcode.com/problems/valid-palindrome/

# https://neetcode.io/problems/string-encode-and-decode?list=neetcode150

class Solution:
    def isPalindrome(self, strs: str) -> bool:
        s = 0
        n = len(strs)
        e = n - 1
        
        while s < e:
            if not strs[s].isalnum():
                s += 1
                continue
            if not strs[e].isalnum():
                e -= 1
                continue
            if strs[s].lower() != strs[e].lower():
                return False
            else:
                s += 1
                e -= 1
    
        return True
        
