# 这样判断，无法判断顺序，有重复的无法重新开始判断

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1:
            return s

        curr_find = []
        max_len = 0
        for char in s:
            if char not in curr_find:
                curr_find.append(char)
                max_len = max(len(curr_find), max_len)

        return max_len






            