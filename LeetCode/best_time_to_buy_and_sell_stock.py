#!/usr/bin/python

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
      if len(prices) == 0: return 0
      min_price = [prices[0]]
      ans = 0
      for i in range(1, len(prices)):
        if (prices[i] - min_price[i-1] > ans):
          ans = prices[i] - min_price[i-1]
        if prices[i] < min_price[i-1]:
          min_price.append(prices[i])
        else:
          min_price.append(min_price[-1])
      return ans
