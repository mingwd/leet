# work 但是这个很慢


class Solution:
        
    def jump(self, nums: List[int]) -> int:

        paths = [(0, 0)] * len(nums)

        curr_index = 0
        stop = False

        while curr_index < len(nums) - 1 and not stop:
            val = nums[curr_index]
            for goto in range(1, val + 1):
                step = paths[curr_index][0] + 1
                if paths[curr_index + goto][0] == 0:
                    paths[curr_index + goto] = (step, curr_index)
                if curr_index + goto == len(nums) - 1:
                    return paths[-1][0]

            curr_index += 1

        return 0
    


class Solution:
    def jump(self, nums: List[int]) -> int:

        steps,curr_max,new_max = 0,0,0

        for i in range(len(nums)-1):
            if i+nums[i]>new_max:
                new_max = i+nums[i]
            if i==curr_max:
                steps+=1
                curr_max = new_max
        return steps
    
# use i > curr_max to test if can't reach end