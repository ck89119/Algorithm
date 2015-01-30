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
      while i + 1 < n and A[i] < A[i+1]:
        i += 1
      if i + 1 >= n:
        return self.b_search(A, target, 0, i)
      else:
        ans = self.b_search(A, target, 0, i)
        if ans != -1: return ans
        return self.b_search(A, target, i+1, n-1)

ss = Solution()
A = [2, 3, 4, 0, 1]
target = 1
print ss.search(A, target)


