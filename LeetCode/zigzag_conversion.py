#!/usr/bin/python

class Solution:
    # @return a string
    def convert(self, s, nRows):
      if nRows == 1: return s
      n = len(s)
      ans = ''
      i = 0
      while i < nRows:
        k = i
        while k < n:
          ans += s[k]
          if i != 0 and i != nRows - 1 and k + 2*(nRows-1)-2*i < n:
            ans += s[k+2*(nRows-1)-2*i]
          k += 2 * (nRows-1)
        i += 1
      return ans

ss = Solution()
s = 'PAYPALISHIRING'
print ss.convert(s, 3)
