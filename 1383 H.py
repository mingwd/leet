import heapq
from typing import List

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10**9 + 7
        
        # Create a list of tuples (efficiency, speed) and sort by efficiency in descending order
        engineers = sorted(zip(efficiency, speed), reverse=True, key=lambda x: x[0])
        
        speed_sum = 0  # Current sum of selected speeds
        max_performance = 0  # Max performance encountered so far
        speed_heap = []  # Min-heap to track the top k speeds
        
        # Iterate through the sorted engineers
        for eff, spd in engineers:
            # Add the current engineer's speed to the heap
            heapq.heappush(speed_heap, spd)
            speed_sum += spd
            
            # If the number of engineers exceeds k, remove the smallest speed
            if len(speed_heap) > k:
                speed_sum -= heapq.heappop(speed_heap)
            
            # Calculate the performance with the current engineer as the minimum efficiency
            performance = speed_sum * eff
            max_performance = max(max_performance, performance)
        
        # Return the result modulo 10^9 + 7
        return max_performance % MOD
