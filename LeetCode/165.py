#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        list1 = version1.split('.')
        while len(list1) > 0 and int(list1[-1]) == 0:
            list1 = list1[:-1]
        list2 = version2.split('.')
        while len(list2) > 0 and int(list2[-1]) == 0:
            list2 = list2[:-1]

        for i in range(max(len(list1), len(list2))):
            if len(list1) <= i:
                return -1
            if len(list2) <= i:
                return 1
            n1 = int(list1[i])
            n2 = int(list2[i])
            if n1 < n2:
                return -1
            if n1 > n2:
                return 1
        return 0
