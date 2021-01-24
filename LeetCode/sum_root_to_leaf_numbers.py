#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def dfs(self, root, s, ans):
      if root.left == None and root.right == None:
        ans.append(s)
        return
      if root.left != None:
        self.dfs(root.left, s*10+root.left.val, ans)
      if root.right != None:
        self.dfs(root.right, s*10+root.right.val, ans)

    
    def sumNumbers(self, root):
      if root == None: return 0
      ans = []
      self.dfs(root, root.val, ans)
      for i in range(1, len(ans)):
        ans[0] += ans[i]
      return ans[0]
