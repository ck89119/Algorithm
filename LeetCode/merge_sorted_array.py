#!/usr/bin/python

class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
      i = m - 1
      while i >= 0:
        A[i+n] = A[i]
        i -= 1
      print A
      i = n
      j = 0
      k = 0
      while i < n + m and j < n:
        if A[i] < B[j]:
          A[k] = A[i]
          i += 1
          k += 1
        else:
          A[k] = B[j]
          j += 1
          k += 1

      if j < n:
        while j < n:
          A[k] = B[j]
          j += 1
          k += 1

sol = Solution()
A = [1, 2, 3, 4]
B = [2]
sol.merge(A, 1, B, 1)
print A
