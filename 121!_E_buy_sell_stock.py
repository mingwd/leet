class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0

        buy_n_sell = (0, 0)

        sell_date = 0
        buy_date = 0

        for i in prices:
            curr_profit = i - min_price
            if curr_profit > max_profit:

                max_profit = curr_profit

                sell_date = prices.index(i) + 1

                buy_n_sell = (buy_date, sell_date)

            if i < min_price:

                min_price = i

                buy_date = prices.index(i) + 1
        
        return max(max_profit, 0)



# 逻辑有些绕，修改了一下code 可以展示那天买的那天卖的