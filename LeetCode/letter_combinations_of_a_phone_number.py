#!/usr/bin/python

class Solution:
    # @return a list of strings, [s1, s2]
    def dfs(self, digits, map, k, string):
      if k == len(digits):
        if not string in self.ans:
          self.ans.append(string)
        return
      
      digit = int(digits[k])
      if digit <= 1:
        self.dfs(digits, map, k+1, string)

      for i in range(0, len(map[digit])):
        self.dfs(digits, map, k+1, string + map[digit][i])


    def letterCombinations(self, digits):
      map = []
      map.append('')
      map.append('')
      map.append('abc')
      map.append('def')
      map.append('ghi')
      map.append('jkl')
      map.append('mno')
      map.append('pqrs')
      map.append('tuv')
      map.append('wxyz')
      self.ans = []
      self.dfs(digits, map, 0, '')
      return self.ans

s = Solution()
print s.letterCombinations('22')

