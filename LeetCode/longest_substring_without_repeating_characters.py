#!/usr/bin/python

class Solution:
    # @return an integer
    def search(self, s, l, r):
      count = [0] * 26
      i = l
      while i <= r:
        t = ord(s[i]) - ord('a')
        if count[t] == 0:
          count[t] += 1
        else:
          return False
        i += 1
      return True
    
    def lengthOfLongestSubstring(self, s):
      n = len(s)
      l = 1
      r = 27
      while l+1 < r:
        mid = (l+r) / 2
        i = 0
        flag = False
        while i + mid - 1 < n:
          if self.search(s, i, i+mid-1):
            flag = True
          i += 1
        if flag:
          l = mid
        else:
          r = mid
      return l


ss = Solution()
s = 'ityvnqitzvgcyqezmnpydkrsniczxiyidzdspolqjttkmzjaobyrnpka'
print ss.lengthOfLongestSubstring(s)

