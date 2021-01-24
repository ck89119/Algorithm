#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @return a list of tree node
    def copy_tree(self, root):
      if root == None:
        return None
      node = TreeNode(root.val)
      node.left = self.copy_tree(root.left)
      node.right = self.copy_tree(root.right)
      return node

    def dfs(self, l, r, root, cur):
      i = l
      while i <= r:
        self.copy_tree(root)
        :
    def generateTrees(self, n):
      

