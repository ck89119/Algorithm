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

    def maxDepth(self, root):
      if root == None:
        return 0
      
      d1 = 0
      if root.left != None:
        d1 = self.maxDepth(root.left)

      d2 = 0
      if root.right != None:
        d2 = self.maxDepth(root.right)
      
      depth = 1
      if d1 > d2: depth += d1
      else: depth += d2
      return depth
        
