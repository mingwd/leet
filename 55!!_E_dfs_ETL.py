class Solution:
    def canJump(self, nums: List[int]) -> bool:
        return self.dfs(1, nums)
    

    def dfs(self, level, nums):
        find = False
        if level == len(nums):
            return True
        elif level <= len(nums):
            for i in range(1, nums[level - 1] + 1):
                find = self.dfs(level + i, nums) or find
            return find
        
# 上面那个可以用 但是超时
# 修改一下变成

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        return self.dfs(1, nums)

    def dfs(self, level, nums):
        if level >= len(nums):
            return True

        for i in range(1, nums[level - 1] + 1):
            if self.dfs(level + i, nums):
                return True

        return False

# 下面这个最好, 还是没过， ETL

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        invalid_path = set() # 很关键！！！！！！
        return self.dfs(1, nums, invalid_path)

    def dfs(self, level, nums, invalid_path):

        if level == len(nums):
            return True
        
        if level in invalid_path:
            return False

        for i in range(1, nums[level - 1] + 1):
            if self.dfs(level + i, nums, invalid_path):
                return True
            
        invalid_path.add(level)

        return False
    

    # greedy


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reach = 0
        for i, val in enumerate(nums):
            if i > max_reach:
                return False
            else:
                max_reach = max(max_reach, i + val)
        
        return True