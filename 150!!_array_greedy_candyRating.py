# my method, not quick and space efficient
# greedy two way check

class Solution:
    def candy(self, ratings: List[int]) -> int:

        if len(ratings) == 1:
            return 1

        childrens1 = [1] * len(ratings)
        childrens2 = [1] * len(ratings)
        
        index = 1
        while index < len(ratings):
            if ratings[index] > ratings[index - 1]:
                childrens1[index] = childrens1[index - 1] + 1
            index += 1

        index = len(ratings) - 2
        while index > -1:
            if ratings[index] > ratings[index + 1]:
                childrens2[index] = childrens2[index + 1] + 1
            index -= 1

        index = 0

        while index < len(ratings):
            childrens1[index] = max(childrens1[index], childrens2[index])
            index += 1
        
        return sum(childrens1)

        
# O1 space

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 1:
            return 1
        
        candies = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        
        total_candies = candies[-1]
        right = 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right += 1
                total_candies += max(candies[i], right) # can be combined outside loop
            else:
                right = 1
                total_candies += candies[i] # with this line
        
        return total_candies


