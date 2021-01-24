#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
      if len(num) == 0: return None
      length = len(num)
      node = TreeNode(num[length/2])
      node.left = self.sortedArrayToBST(num[0:length/2])
      node.right = self.sortedArrayToBST(num[length/2+1:])
      return node
