from typing import List

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        # Convert points to a set for fast lookup
        point_set = set(map(tuple, points))
        min_area = float('inf')  # Initialize the minimum area to infinity
        
        # Iterate over all pairs of points
        for i in range(len(points)):
            x1, y1 = points[i]
            for j in range(i + 1, len(points)):
                x2, y2 = points[j]
                
                # Check if the points can form a diagonal of a rectangle
                if x1 != x2 and y1 != y2:
                    # Check if the other two points of the rectangle exist
                    if (x1, y2) in point_set and (x2, y1) in point_set:
                        # Calculate the area of the rectangle
                        area = abs(x2 - x1) * abs(y2 - y1)
                        min_area = min(min_area, area)
        
        # If no rectangle is found, return 0
        return 0 if min_area == float('inf') else min_area
