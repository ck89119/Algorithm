#!/usr/bin/python

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
      n = len(intervals)
      i = 0
      while i < n and newInterval.start > intervals[i].start:
        i += 1
      intervals[i:i] = [newInterval]
      i = 0
      while i+1 < len(intervals):
        if intervals[i].end >= intervals[i+1].start:
          intervals[i].end = max(intervals[i].end, intervals[i+1].end)
          del intervals[i+1]
          i -= 1
        i += 1
      return intervals

ss = Solution()
intervals = []
i1 = Interval(1,3)
i2 = Interval(6,9)
intervals.append(i1)
intervals.append(i2)
newInterval = Interval(2,5)
ans = ss.insert(intervals, newInterval)
for i in ans:
  print i.start, i.end
