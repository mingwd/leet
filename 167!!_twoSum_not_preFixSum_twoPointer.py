# 正确的 twoSum 解法：基于 hash map 存“补数”
# 这题是两个数相加，所以只要看两个数就可以了
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mydict = {}
        for i, num in enumerate(numbers):
            gap = target - num
            if gap in mydict:
                return [mydict[gap]+1, i+1]
            mydict[num] = i

# 但是这题得用双指针来做，应为space不能超过constant

# 下面这个是很慢的双指针解法，会ETL，不对，这个不是双指针！！
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i, num in enumerate(numbers):
            j = i + 1
            stop = False
            while j < len(numbers) and not stop:
                
                sum = numbers[i] + numbers[j]
                if sum == target:
                    return [i + 1, j + 1]
                if sum > target:
                    stop = True

                j += 1

# 这才是真正的双指针解法
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                left += 1