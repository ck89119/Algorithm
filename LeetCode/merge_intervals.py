#!/usr/bin/python

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def my_key(self, i):
      return i.start

    def merge(self, intervals):
      intervals = sorted(intervals, key=self.my_key)
      n = len(intervals)
      i = 0
      while i+1 < len(intervals):
        if intervals[i].end >= intervals[i+1].start:
          intervals[i].end = max(intervals[i].end, intervals[i+1].end)
          del intervals[i+1]
          i -= 1
        i += 1
      return intervals

ss = Solution()
i1 = Interval(1,3)
i2 = Interval(2,6)
i3 = Interval(8,10)
i4 = Interval(15,18)
intervals = []
intervals.append(i2)
intervals.append(i1)
intervals.append(i3)
intervals.append(i4)
inter = ss.merge(intervals)
for i in inter:
  print i.start, i.end
