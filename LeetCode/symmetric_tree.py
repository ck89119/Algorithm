#!/usr/bin/python1

# Definition for a  binary tree node
# class TreeNode:
#   def __init__(self, x):
#     self.val = x
#     self.left = None
#     self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isSame(self, r1, r2):
      if r1 == None and r2 == None: return True
      if r1 == None and r2 != None: return False
      if r1 != None and r2 == None: return False
      if r1.val != r2.val: return False
      return self.isSame(r1.left, r2.right) and self.isSame(r1.right, r2.left)
    
    def isSymmetric(self, root):
      if root == None: return True
      return self.isSame(root.left, root.right)
