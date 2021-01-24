#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
      if len(A) == 0: return 0  
      s = []
      s.append(A[0])
      for i in range(1, len(A)):
        if s[i-1] >= 0:
          s.append(s[i-1]+A[i])
        else:
          s.append(A[i])
      
      ans = s[0]
      for i in range(1, len(s)):
        if s[i] > ans: ans = s[i]

      return ans
