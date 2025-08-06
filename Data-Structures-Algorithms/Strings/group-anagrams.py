# https://leetcode.com/problems/group-anagrams/description/

# https://neetcode.io/problems/anagram-groups?list=neetcode150

class Solution:
    def get_frozenset_freq(self, s):
        # if all strings contain only alpha numeric values 
        # then you can create a list of freq (not dict) of its ascii value as its index
        freq = dict()
        for c in s:
            freq[c] = 1 + freq.get(c, 0)
        return frozenset(freq.items()) 

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        similar_dict = dict()

        for s in strs:
            s_key = self.get_frozenset_freq(s)
            curr_strs = similar_dict.get(s_key, [])
            print(s, s_key, curr_strs)
            curr_strs.append(s)
            similar_dict[s_key] = curr_strs

        return list(similar_dict.values())


        