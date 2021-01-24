#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def buildTree(self, inorder, postorder):
      if len(inorder) == 0: return None
      root = TreeNode(postorder[-1])
      index = 0
      while inorder[index] != root.val:
        index += 1
      root.left = self.buildTree(inorder[0:index], postorder[0:index])
      root.right = self.buildTree(inorder[index+1:], postorder[index:-1])
      return root
