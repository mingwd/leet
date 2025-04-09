class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        day = 1
        profit = 0
        while day < len(prices):
            if prices[day] > prices[day - 1]:
                profit = profit + prices[day] - prices[day - 1]
            day += 1

        return profit