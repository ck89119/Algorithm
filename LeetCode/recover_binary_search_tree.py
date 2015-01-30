#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a tree node
    def dfs(self, root):
      if root == None: return
      self.dfs(root.left)
      self.num.append(root.val)
      self.dfs(root.right)

    def dfs2(self, root):
      if root.left != None:
        self.dfs2(root.left)
      root.val = self.num[self.cur]
      self.cur += 1
      if root.right != None:
        self.dfs2(root.right)
    
    def recoverTree(self, root):
      if root == None: return root
      self.num = []
      self.dfs(root)
      self.num.sort()
      self.cur = 0
      self.dfs2(root)
      return root
