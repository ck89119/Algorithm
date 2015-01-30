#!/usr/bin/python

class Solution:
    # @return a boolean
    def sameLetter(self, s1, s2):
      num1 = [0] * 26;
      num2 = [0] * 26;
      for ch in s1:
        num1[ord(ch) - ord('a')] += 1;
      for ch in s2:
        num2[ord(ch) - ord('a')] += 1;
      for i in range(0, 26):
          if num1[i] != num2[i]:
            return False;
      return True;

    def check(self, s1, s2):
      #print s1, s2
      if len(s1) != len(s2): return False
      if s1 == s2: return True
      if len(s1) == 1:
        if s1 == s2:
          return True
        else:
          return False
      if len(s1) == 2:
        if s1[0] == s2[1] and s1[1] == s2[0]:
          return True
        else:
          return False
      for i in range(1, len(s1)):
          ans1 = self.sameLetter(s1[0:i], s2[0:i]) and self.sameLetter(s1[i:], s2[i:]) and \
                  self.check(s1[0:i], s2[0:i]) and self.check(s1[i:], s2[i:])
          if ans1: return True
          ans2 = self.sameLetter(s1[0:i], s2[-i:]) and self.sameLetter(s1[i:], s2[0:-i]) and \
                  self.check(s1[0:i], s2[-i:]) and self.check(s1[i:], s2[0:-i])
          if ans2: return True
          #ans3 = self.check(s1[-i:], s2[-i:]) and self.check(s1[0:-i], s2[0:-i])
          #if ans3: return True
          #ans4 = self.check(s1[-i:], s2[0:i]) and self.check(s1[0:-i], s2[i:])
          #if ans4: return True
      return False

    def isScramble(self, s1, s2):
      return self.check(s1, s2)
    
s = Solution()
print s.isScramble('abcdd', 'dbdac')
