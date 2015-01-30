class Solution:
    # @return a string
    def count(self, s, index):
      i = index
      c = 1
      while i+1 < len(s) and s[i+1] == s[i]:
        i += 1
        c += 1
      return c

    def countAndSay(self, n):
      i = 1
      s = '1'
      while i < n:
        tmp = ''
        index = 0
        while index < len(s):
          c = self.count(s, index)
          tmp += str(c)
          tmp += s[index]
          index += c
        s = tmp
        i += 1
      return s

ss = Solution()
for i in range(10):
  print ss.countAndSay(i) 
