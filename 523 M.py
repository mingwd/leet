from typing import List

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # Dictionary to store (remainder, index)
        remainder_map = {0: -1}  # Initialize with remainder 0 at index -1
        prefix_sum = 0

        for i, num in enumerate(nums):
            prefix_sum += num
            
            # Handle the modulo operation (k != 0)
            if k != 0:
                prefix_sum %= k
            
            # If the remainder is already in the map
            if prefix_sum in remainder_map:
                # Check if the subarray length is at least 2
                if i - remainder_map[prefix_sum] > 1:
                    return True
            else:
                # Store the first occurrence of this remainder
                remainder_map[prefix_sum] = i
        
        return False
