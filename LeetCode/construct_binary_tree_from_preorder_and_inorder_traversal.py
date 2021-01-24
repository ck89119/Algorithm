#!/usr/bin/python

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
      if len(inorder) == 0: return None
      root = TreeNode(preorder[0])
      index = 0
      while inorder[index] != root.val:
        index += 1
      root.left = self.buildTree(preorder[1:index+1], inorder[0:index])
      root.right = self.buildTree(preorder[index+1:], inorder[index+1:])
      return root
