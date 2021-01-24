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
    def isBalanced(self, root):
      if root == None: return True
      
      flag1 = self.isBalanced(root.left)
      if flag1 == False: return False
      
      flag2 = self.isBalanced(root.right)
      if flag2 == False: return False
      
      if root.left == None: h1 = 0
      else: h1 = root.left.val
      if root.right == None: h2 = 0
      else: h2 = root.right.val
      
      root.val = 1
      if h1 > h2: root.val += h1
      else: root.val += h2
      
      if abs(h1 - h2) <= 1: return True
      else return False

