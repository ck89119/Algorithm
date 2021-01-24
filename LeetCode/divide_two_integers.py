#!/usr/bin/python

class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
      op = 0
      if dividend < 0:
        dividend = 0 - dividend
        op ^= 1
      if divisor < 0:
        divisor = 0 -divisor
        op ^= 1
      m = divisor
      n = 1
      while m < dividend:
        m <<= 1
        n <<= 1
      # print mul_twopow
      ans = 0
      while dividend >= divisor:
        while m > dividend: 
          m >>= 1
          n >>= 1
        dividend -= m
        ans += n
      if op == 1:
        ans = 0 - ans
      return ans

sln = Solution()
print sln.divide(101, 7)
