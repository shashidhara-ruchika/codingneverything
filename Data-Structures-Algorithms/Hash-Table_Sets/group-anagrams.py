# https://leetcode.com/problems/group-anagrams/submissions/1218627467/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict = {}
        for s in strs:
            sorted_str = "".join(sorted(s))

            if sorted_str not in anagram_dict:
                anagram_dict[sorted_str] = [s]
            else:
                anagram_dict[sorted_str].append(s)
        return list(anagram_dict.values())
            