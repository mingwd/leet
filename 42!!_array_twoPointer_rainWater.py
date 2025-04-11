# close to 150 candy problem

class Solution:
    def trap(self, height: List[int]) -> int:

        size = len(height)

        max_height_left = [0] * size
        max_height_right = [0] * size

        curr_max = 0
        for i in range(0, size):
            if curr_max < height[i]:
                curr_max = height[i]
            max_height_left[i] = curr_max
        
        curr_max = 0
        for i in range(size - 1, -1, -1):
            if curr_max < height[i]:
                curr_max = height[i]
            max_height_right[i] = curr_max

        result = 0
        for i in range(0, size):
            result += min(max_height_left[i], max_height_right[i]) - height[i]
        return result


# two check from left to right and from right to left but not good enough, there's O1 two pointer solution
class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) -1 # left & right search index
        l_max, r_max = 0, 0
        total_water = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] >= l_max: # 这他妈是关键！！，l-max一定比height【right】小
                    l_max = height[left]
                else:
                    total_water += l_max - height[left]
                left += 1
            else:
                if height[right] > r_max:
                    r_max = height[right]
                else:
                    total_water += r_max - height[right]
                right -= 1
        
        return total_water