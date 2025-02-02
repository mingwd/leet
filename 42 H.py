import heapq
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height or len(height) < 3:
            return 0  # Not enough bars to trap water
        
        left, right = 0, len(height) - 1  # Two pointers
        max_left, max_right = 0, 0  # Variables to store the maximum heights
        trapped_water = 0  # Total water trapped
        
        while left < right:
            if height[left] < height[right]:
                # Process left side
                if height[left] >= max_left:
                    max_left = height[left]
                else:
                    trapped_water += max_left - height[left]
                left += 1
            else:
                # Process right side
                if height[right] >= max_right:
                    max_right = height[right]
                else:
                    trapped_water += max_right - height[right]
                right -= 1
        
        return trapped_water
    



# not optimized but ez to understand
"""

    class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n == 0:
            return 0
        
        # Step 1: Precompute max_left
        max_left = [0] * n
        max_left[0] = height[0]
        for i in range(1, n):
            max_left[i] = max(max_left[i - 1], height[i])
        
        # Step 2: Precompute max_right
        max_right = [0] * n
        max_right[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            max_right[i] = max(max_right[i + 1], height[i])
        
        # Step 3: Calculate trapped water
        total_water = 0
        for i in range(n):
            total_water += max(0, min(max_left[i], max_right[i]) - height[i])
        
        return total_water


        """