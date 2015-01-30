class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
      tmp = []
      tmp.extend(num)
      num.sort()
      index1 = 0
      index2 = len(num) - 1
      while index1 < index2:
        while (num[index2] > target - num[index1]):
          index2 -= 1
        if (num[index2] == target - num[index1]):
          ans1 = num[index1]
          ans2 = num[index2]
          break
        index1 += 1
      
      i = 0
      while i < len(tmp):
        if (ans1 == tmp[i]):
          index1 = i
          break
        i += 1

      i = 0
      while i < len(tmp):
        if (i != index1 and ans2 == tmp[i]):
          index2 = i
          break
        i += 1
      
      if index1 > index2:
        t = index1
        index1 = index2
        index2 = t

      return (index1+1, index2+1)
