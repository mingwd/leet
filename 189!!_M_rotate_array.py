# 这个会超时
# 卧槽他妈的，可以用%处理下周期，这样看offset就行, 但是还超时，得想新办法了

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        k = k % size

        if len(nums) != 1:
            while k > 0:
                nums = self.rotate_once(nums, size)
                k -= 1

    



    def rotate_once(self, nums: List[int], size: int):
        for i in range(1, size):
            temp1 = nums[i]
            nums[i] = nums[0]
            nums[0] = temp1

        return nums
    




class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)

        self.flip(nums, 0, len(nums) - 1)
        self.flip(nums, 0, k - 1)
        self.flip(nums, k, len(nums) - 1)



        
        
    def flip(self, nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
        