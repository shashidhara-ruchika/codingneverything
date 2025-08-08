# https://leetcode.com/problems/encode-and-decode-strings/description/

# https://neetcode.io/problems/string-encode-and-decode?list=neetcode150

class Solution:

    def encode(self, strs: List[str]) -> str:
        
        encoded_str = ""
        for string in strs:
            for char in string:
                encoded_str += char + char
            encoded_str += "01"

        print(encoded_str)
        return encoded_str


    def decode(self, s: str) -> List[str]:
        
        decoded_list = []
        curr_str = ""
        for i in range(0, len(s), 2):
            if s[i] != s[i + 1]:
                decoded_list.append(curr_str)
                curr_str = ""
            else:
                curr_str += s[i]

        print(decoded_list)
        return decoded_list





