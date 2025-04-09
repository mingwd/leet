class Solution:
    def hIndex(self, citations: List[int]) -> int:
        max_min = sorted(citations, reverse=True)

        start = 0

        while start < len(max_min) and max_min[start] >= start + 1:
            start += 1

        print(max_min)

        return start


