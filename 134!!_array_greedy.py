# ETL !! USE greedy

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start_index = 0
        while start_index < len(gas):
            if self.helper(gas, cost, start_index):
                return start_index
            start_index += 1
        return -1

    def helper(self, gas, cost, index):
        cycle = 0
        total_gas = 0
        while cycle < len(gas):
            total_gas += gas[index]
            if total_gas < cost[index]:
                return False
            total_gas -= cost[index]
            index = (index + 1) % len(gas)
            cycle += 1
        
        return True

        
# remember if tank < 0, past pathes doesn't contain valid starting point

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        
        i = 0
        tank = 0
        result = 0

        while i < len(gas):
            tank += gas[i] - cost[i]

            if tank < 0:
                result = i + 1
                tank = 0

            i += 1
            
        return result

            
