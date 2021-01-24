#!/usr/bin/python

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
      if len(prices) <= 1: return 0
      diff = []
      for i in range(1, len(prices)):
        diff.append(prices[i]-prices[i-1])
      d = []
      i = 0
      while i < len(diff):
        
