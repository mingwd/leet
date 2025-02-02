from collections import deque
from typing import List

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        height = [[-1] * n for _ in range(m)]  # Initialize height matrix with -1
        queue = deque()  # BFS queue
        
        # Add all water cells to the queue with height 0
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    height[i][j] = 0
                    queue.append((i, j))
        
        # Directions for adjacent cells (north, east, south, west)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS
        while queue:
            x, y = queue.popleft()
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                # Check if the neighbor is within bounds and unvisited
                if 0 <= nx < m and 0 <= ny < n and height[nx][ny] == -1:
                    height[nx][ny] = height[x][y] + 1  # Set the height
                    queue.append((nx, ny))  # Add the neighbor to the queue
        
        return height
