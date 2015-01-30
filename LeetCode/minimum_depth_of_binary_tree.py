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
    def minDepth(self, root):
      if root == None: return 0
      if root.left == None and root.right == None: return 1

      h1 = 99999999999
      if root.left != None:
        h1 = self.minDepth(root.left)
      h2 = 99999999999
      if root.right != None:
        h2 = self.minDepth(root.right)

      return min(h1, h2) + 1
