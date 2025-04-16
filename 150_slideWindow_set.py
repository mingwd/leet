class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1:
            return 1

        left = 0
        max_len = 0
        visited = set()

        for right in range(len(s)):

            while s[right] in visited:
                visited.remove(s[left])
                left += 1
            
            visited.add(s[right])
            max_len = max(max_len, right - left + 1)
        

        return max_len