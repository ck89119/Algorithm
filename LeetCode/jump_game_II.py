#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
      n = len(A)
      if n == 0: return 0
      step = [999999 for i in range(n)]
      step[-1] = 0
      i = n - 2
      while i >= 0:
        j = 1
        while j <= A[i] and i + j < n:
          step[i] = min(step[i], step[i+j]+1)
          j += 1
        i -= 1
      return step[0]

ss = Solution()
A = [2,3,1,1,4]
#i = 25000
#while i > 0:
#  A.append(i)
#  i -= 1
print ss.jump(A)

