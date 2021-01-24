#!/usr/bin/python

class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def b_search(self, num, l, r, target):
      while l <= r:
        mid = (l + r) / 2
        if num[mid] == target: return mid
        if num[mid] < target:
          l = mid + 1
        if num[mid] > target:
          r = mid - 1
      return -1
    
    def dfs(self, num, v, k):
      if len(v) == 2:
        v0 = v[0]
        v1 = v[1]
        index = self.b_search(num, k, len(num)-1, -(v[0]+v[1]))
       # print v0, v1, index
        if index != -1:
          if [v0, v1, num[index]] not in self.ans:
            #print v0, v1, num[index]
            self.ans.append([v0, v1, num[index]])
      
      if k >= len(num): return

      self.dfs(num, v, k+1)
      i = k
      while i < len(num):
        v.append(num[i])
        self.dfs(num, v, i+1)
        del v[-1]
        i += 1
    
    def threeSum(self, num):
      num.sort()
      #print num
      self.ans = []
      self.dfs(num, [], 0)
      return self.ans
      

ss = Solution()
num = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
print ss.threeSum(num)
