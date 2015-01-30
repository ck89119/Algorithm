#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def dfs(self, root):
      ans1 = root.val
      ans2 = root.val
      flag = True

      if root.left != None:
        (l, r, f) = self.dfs(root.left)
        if not f or r >= root.val: flag = False
        ans1 = l
      if root.right != None:
        (l, r, f) = self.dfs(root.right)
        if not f or l <= root.val: flag = False
        ans2 = r
      
      return (ans1, ans2, flag)
    
    def isValidBST(self, root):
      if root == None: return True
      (l, r, f) = self.dfs(root)
      return f
