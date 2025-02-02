from collections import defaultdict
from typing import List


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 2:
            return len(points)  # All points are on the same line if there are 2 or fewer points
        
        max_points = 0
        
        for i in range(len(points)):
            slopes = defaultdict(int)  # Store slope frequencies
            duplicate = 1  # Count the current point itself
            
            for j in range(len(points)):
                if i == j:
                    continue
                
                x1, y1 = points[i]
                x2, y2 = points[j]
                
                # Check if the points are the same
                if x1 == x2 and y1 == y2:
                    duplicate += 1
                else:
                    # Calculate slope as a float
                    if x2 == x1:  # Handle vertical lines (infinite slope)
                        slope = float('inf')
                    else:
                        slope = (y2 - y1) / (x2 - x1)
                    
                    slopes[slope] += 1
            
            # Find the maximum points on a line passing through the current point
            current_max = max(slopes.values(), default=0) + duplicate
            max_points = max(max_points, current_max)
        
        return max_points
