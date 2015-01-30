#!/usr/bin/python

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
      dif = []
      i = 0;
      while i < len(prices) - 1:
        dif.append(prices[i+1] - prices[i])
        i += 1

      ans = 0
      i = 0;
      while i < len(dif):
        if dif[i] > 0: ans += dif[i]
        i += 1
      return ans
