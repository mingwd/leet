class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        window_front = 0
        window_end = 0
        insert_location = 0

        while window_front < len(nums):

            appear_count = 0
            while window_front < len(nums) and nums[window_front] == nums[window_end]:
                appear_count += 1
                window_front += 1

            window_end = window_front
            
            if appear_count > 1:
                nums[insert_location] = nums[window_front - 1]
                insert_location += 1
                nums[insert_location] = nums[window_front - 1]
            else:
                nums[insert_location] = nums[window_front - 1]

            insert_location += 1

        return insert_location

