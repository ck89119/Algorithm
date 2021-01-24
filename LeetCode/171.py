#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        for ch in s:
            ans = ans * 26 + ord(ch) - ord('A') + 1
        return ans

s = Solution()
print s.titleToNumber('A')
print s.titleToNumber('Z')
print s.titleToNumber('AA')
print s.titleToNumber('AZ')
print s.titleToNumber('ZZ')
print s.titleToNumber('AAA')
