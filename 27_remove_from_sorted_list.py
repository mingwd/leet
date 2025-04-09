class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        back = -1
        back_index = len(nums) - 1
        front = 0
        findSoFar = 0

        while front <= back_index:

            if nums[front] == val:
                nums[front], nums[back] = nums[back], nums[front]
                back -= 1
                back_index -= 1

                while front <= back_index and nums[front] == val:
                    nums[front], nums[back] = nums[back], nums[front]
                    back -= 1
                    back_index -= 1
            
            front += 1

        findSoFar = len(nums) - 1 - back_index

        print(findSoFar)
        print(nums)
    
        return len(nums) - findSoFar