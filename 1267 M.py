import heapq
from typing import List

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # Count number of servers in each row and each column
        row_count = [0] * m
        col_count = [0] * n
        
        # Populate row_count and col_count
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    row_count[i] += 1
                    col_count[j] += 1
        
        # Count servers that can communicate with at least one other server
        total_communicable = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    # A server can communicate if its row or column has more than one server
                    if row_count[i] > 1 or col_count[j] > 1:
                        total_communicable += 1
        
        return total_communicable
