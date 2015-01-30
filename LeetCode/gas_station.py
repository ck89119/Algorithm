#!/usr/bin/python

class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
      n = len(gas)
      for i in range(0, n):
        gas[i] -= cost[i]
      left = 0
      for i in range(0, n):
        j = i
        count = 0
        while count < n:
          left += gas[j]
          if left < 0:
            break
          j += 1
          j %= n
          count += 1
        if count >= n:
          return i
      return -1
