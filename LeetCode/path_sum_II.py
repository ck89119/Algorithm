#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def dfs(self, root, s, sum, ans):
      if root.left == None and root.right == None:
        tmp_sum = 0
        for i in range(0, len(s)):
          tmp_sum += s[i]
        if tmp_sum == sum:
          ans.append(s)
        return
      
      if root.left != None:
        s_tmp = []
        s_tmp.extend(s)
        s_tmp.append(root.left.val)
        self.dfs(root.left, s_tmp, sum, ans)
      if root.right != None:
        s_tmp = []
        s_tmp.extend(s)
        s_tmp.append(root.right.val)
        self.dfs(root.right, s_tmp, sum, ans)
          
    
    def pathSum(self, root, sum):
      if root == None: return []
      ans = []
      s = [root.val]
      self.dfs(root, s, sum, ans)
      return ans

