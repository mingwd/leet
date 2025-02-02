class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
#Sort based on the cost difference(bCost - aCost)
        costs.sort(key=lambda x: x[1] - x[0])
        
        n = len(costs) // 2
        total_cost = 0

#Assign first n people to city A and the rest to city B
        for i in range(n):
            total_cost += costs[i][0]  # Cost for city A
        for i in range(n, 2 * n):
            total_cost += costs[i][1]  # Cost for city B
        
        return total_cost
