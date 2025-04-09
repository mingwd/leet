class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        insertIndex = 1

        size = len(nums)

        index = 1

        while index < len(nums):
            if nums[index] != nums[index -1]:
                nums[insertIndex] = nums[index]
                insertIndex += 1

            index += 1

        return insertIndex