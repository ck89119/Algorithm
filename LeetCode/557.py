#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        ans = ''
        for word in words:
            ans += word[::-1] + ' '
        return ans[:-1]
