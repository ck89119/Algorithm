#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def b_search(self, A, target, l, r):
      while l <= r:
        mid = (l + r) / 2
        if A[mid] == target: return mid
        if A[mid] < target:
          l = mid + 1
        if A[mid] > target:
          r = mid - 1
      return -1
    
    def search(self, A, target):
      n = len(A)
      i = 0
      while i + 1 < n and A[i] <= A[i+1]:
        i += 1
      # print i
      if i + 1 >= n:
        if self.b_search(A, target, 0, i) == -1:
          return False
        else:
          return True
      else:
        ans = self.b_search(A, target, 0, i)
        if ans != -1: return True
        ans = self.b_search(A, target, i+1, n-1)
        if ans == -1:
          return False
        else:
          return True

ss = Solution()
A = [2, 2, 2, 0, 1]
target = 1
print ss.search(A, target)
